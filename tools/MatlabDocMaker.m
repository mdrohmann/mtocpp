classdef MatlabDocMaker
% MatlabDocMaker: Automated documentation creation using doxygen and mtoc++ from within MatLab
%
% Currently documentation creation for unix and windows environment is
% supported.
%
% Prerequisites:
% The following tools must be installed and present on the PATH or
% reside inside the folder returned by
% MatlabDocMaker.getConfigDirectory.
% - \c mtocpp, \c mtocpp_post (the main tool)
% - \c doxygen (mtoc++ is a filter for doxygen)
% - \c m4: A macro processor
%
% Strongly recommended:
% - \c latex Doxygen supports built-in latex formulas and
% MatlabDocMaker/mtoc++ allows for easy extra latex inclusions and
% notation in code
% - \c dot Doxygen creates really nice inheritance graphs and
% collaboration diagrams with dot.
%
% @author Daniel Wirtz @date 2011-10-13
%
% @change{1,3,dw,2012-01-16}
% - Properly using the correct file separators everywhere now
% - Hyperlinked the log file so it can be opened directly
%
% @change{1,3,dw,2012-01-14} Not displaying the "generated warnings"-text if there have not
% been any during documentation creation.
%
% @change{1,2,dw,2011-11-27}
% - Included documentation creation for the Windows platform and
% combined the old methods into one (small effective differences)
% - No longer storing the doxygen binary file in the prefs as a lot of
% tools must be present on the path anyways. The new paradigm is to
% expect all required 3rd-party programmes to be available on PATH. As
% backup (especially for Win32/m4) the configuration files directory is
% added to the Matlab PATH environment \b nonpermanently and any
% executables found there will thus also be usable.
% - Included checks for \c dot and \c latex at the setup stage to
% recommend installation of those tools if not present (the default
% doxygen settings in Doxyfile.m4 are to use both)
%
% @change{1,2,dw,2011-11-08} Improved the createUnix method by displaying the warnings and writing the output to
% a log file afterwards. Not using cprintf anymore as this is 3rd party software.
%
% @change{1,2,dw,2011-11-07} Fixed a recursion bug caused by copy and paste. Now the preferences
% are stored on an per-application basis.
%
% @change{1,2,dw,2011-11-04} Changed the name to MatlabDocMaker in
% order to export it into the mtoc++ distribution later.
%
% @new{1,2,dw,2011-10-13} Added this class and moved documentation related
% stuff here from the KerMor class.
%
% This class is part of the mtoc++ tool
% - \c Homepage http://www.morepas.org/software/mtocpp/
% - \c License http://www.morepas.org/software/mtocpp/docs/licensing.html
%
% Copyright (c) 2011, Daniel Wirtz
% All rights reserved.
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted only in compliance with the BSD license, see
% http://www.opensource.org/licenses/bsd-license.php
    
    methods(Static)
        function name = getProjectName
            % Returns the project name.
            %
            % @note Changing the return value of this method will require
            % another execution of MatlabDocMaker.setup as the preferences
            % key also depends on it.
            %
            % Return values:
            % name: The project name @type char
            name = 'My mtoc++-powered project';
        end
        
        function version = getProjectVersion
            % Returns the current version of the project.
            %
            % @note The built-in @@new and @@change tags from the
            % Doxyfile.m4 support two-level versioning a la X.X.
            %
            % Return values:
            % version: The project version @type char
            version = '0.1';
        end
    end
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% End of user defined methods.
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    methods(Static, Sealed)
        % The KerMor documentation directory, i.e. where createDocs places
        % the generated documentation.
        %
        % Can be set during Documentation.setup
        %
        
        function dir = getOutputDirectory
            % Returns the directory where the applications source files
            % reside
            %
            % Return values:
            % dir: The output directory @type char
            dir = getpref(MatlabDocMaker.getProjPrefTag,'outdir',[]);
            if isempty(dir)
                error('MatlabDocMaker preferences not set. Re-run setup method.');
            end
        end
        
        function dir = getSourceDirectory
            % Returns the directory where the applications source files
            % reside
            %
            % Return values:
            % dir: The project source directory @type char
            dir = getpref(MatlabDocMaker.getProjPrefTag,'srcdir',[]);
            if isempty(dir)
                error('MatlabDocMaker preferences not set. Re-run setup method.');
            end
        end
        
        function dir = getConfigDirectory
            % Returns the directory where the applications documentation
            % configuration files reside
            %
            % This folder must contain at least the files "mtoc.conf" and
            % "Doxyfile.m4"
            %
            % Return values:
            % dir: The documentation configuration directory @type char
            dir = getpref(MatlabDocMaker.getProjPrefTag,'confdir',[]);
            if isempty(dir)
                error('MatlabDocMaker preferences not set. Re-run setup method.');
            end
        end
    end
        
    methods(Static)
        
        function open
            % Opens the generated documentation.
            web(fullfile(MatlabDocMaker.getOutputDirectory, 'index.html'));
        end
        
        function create(open)
            % Creates the Doxygen documentation
            %
            % Parameters:
            % open: Set to true if the documentation should be opened after
            % successful compilation @type bool @default false
           
            if nargin == 0
                open = false;
            end
            
            % Check for correct setup
            cdir = getpref(MatlabDocMaker.getProjPrefTag,'confdir',[]);
            if isempty(cdir)
                error('No configuration files directory set for project "%s". Have you run MatlabDocMaker.setup?',MatlabDocMaker.getProjectName);
            end
            
            % Save current working dir and change into the KerMor home
            % directory; only from there all classes and packages are
            % detected properly.
            curdir = pwd;
            cd(MatlabDocMaker.getSourceDirectory);
            
            % Append the configuration file directory to the current PATH
            pathadd = [pathsep cdir];
            setenv('PATH',[getenv('PATH') pathadd]);
            
            % Operation-system dependent strings
            strs = struct;
            if isunix
                strs.filter = 'mtocpp_filter.sh';
                strs.farg = '$1';
                strs.null = '/dev/null';
                strs.silencer = '';
            elseif ispc
                strs.filter = 'mtocpp_filter.bat';
                strs.farg = '%1';
                strs.null = 'NUL';
                strs.silencer = '@'; % argh that took a while to figure out..
            else
                error('Current platform not supported.');
            end
            
            %% Actual creation
            cdir = MatlabDocMaker.getConfigDirectory;
            % Create "configured" filter script for inclusion in doxygen 
            cbin = fullfile(cdir,strs.filter);
            f = fopen(cbin,'w');
            fprintf(f,'%smtocpp %s %s',strs.silencer,strs.farg,fullfile(cdir,'mtocpp.conf'));
            fclose(f);
            if isunix
                unix(['chmod +x ' cbin]);
            end
            
            % Process macros in the Doxyfile.m4 file using m4
            doxyfile = fullfile(cdir,'Doxyfile');
            system(sprintf(['m4 -D _OutputDir_="%s" -D _SourceDir_="%s" -D _ConfDir_="%s" -D _ProjectName_="%s"'...
                           ' -D _ProjectVersion_="%s" -D _MTOCFILTER_=%s -D _FileSep_=%s'...
                           ' "%sDoxyfile.m4" > "%s"'],...
                 MatlabDocMaker.getOutputDirectory, MatlabDocMaker.getSourceDirectory, cdir,...
                 MatlabDocMaker.getProjectName, MatlabDocMaker.getProjectVersion, strs.filter, filesep, [cdir filesep], doxyfile));
            
            % Process latex extras
            texm4 = fullfile(cdir,'latexextras.m4');
            tex = fullfile(cdir,'latexextras.sty');
            if exist(texm4,'file') == 2
                % # Parse the kermorlatex include style file
                system(sprintf('m4 -D _ConfDir_="%s" "%s" > "%s"',cdir,texm4,tex));
            else
                % Create empty file
                system(sprintf('echo "" > "%s"',tex));
            end

            % Call doxygen
            fprintf('Running doxygen with mtoc++ filter...\n');
            [~,warn] = system(sprintf('doxygen "%s" 1>%s', doxyfile, strs.null));
             
            % Postprocess
            fprintf('Running mtoc++ postprocessor...\n');
            [~,~] = system(sprintf('mtocpp_post %s',MatlabDocMaker.getOutputDirectory));
            
            % Tidy up
            delete(cbin);
            %delete(tex);
            %delete(doxyfile);
            
            %% Post generation phase 
            cd(curdir);
            
            % Restore PATH to previous value
            curpath = getenv('PATH');
            setenv('PATH',curpath(1:end-length(pathadd)));
            
            % Process warnings
            warn = strtrim(warn);
            if ~isempty(warn)
                fprintf(['Warnings generated during documentation creation:\n' strrep(warn,'\','\\') '\n']);
                % Write to log file later
                log = fullfile(MatlabDocMaker.getOutputDirectory,'warnings.log');
                f = fopen(log,'w'); fprintf(f,'%s',warn); fclose(f);
                fprintf('Complete log file at <a href="matlab:edit(''%s'')">%s</a>.\n',log,log);
                fprintf(2,'MatlabDocMaker finished with warnings!\n');
            else
                fprintf('MatlabDocMaker finished successfully.\n');
            end
            
            % Open index.html if wanted
            if open
                MatlabDocMaker.open;
            end
        end
        
        function setup
            % Runs the setup script for MatlabDocMaker and collects all
            % necessary paths in order for the documentation creation to
            % work properly.
            
            %% Validity checks
            if isempty(MatlabDocMaker.getProjectName) || isempty(MatlabDocMaker.getProjectVersion)
                error('Please set/write the code for the getProjectName and getProjectVersion methods first!');
            end
            fprintf('<<<< Welcome to the MatlabDocMaker setup for your project "%s"! >>>>\n',MatlabDocMaker.getProjectName);
            
            %% Setup directories
            srcdir = getpref(MatlabDocMaker.getProjPrefTag,'srcdir',[]);
            word = 'keep';
            if isempty(srcdir)
                srcdir = pwd;
                word = 'set';
            end
            str = sprintf('Do you want to %s %s as your projects source directory?\n(Y)es/(N)o?: ',word,strrep(srcdir,'\','\\'));
            ds = lower(input(str,'s'));
            if isequal(ds,'n')
                d = uigetdir(srcdir,'Please select the projects source directory');
                if d == 0
                    error('No source directory specified. Aborting setup.');
                end
                srcdir = d;
            end
            setpref(MatlabDocMaker.getProjPrefTag,'srcdir',srcdir);
            
            % Config directory
            confdir = getpref(MatlabDocMaker.getProjPrefTag,'confdir',[]);
            word = 'keep';
            if isempty(confdir)
                confdir = fullfile(srcdir,'documentation');
                word = 'set';
            end
            str = sprintf('Do you want to %s %s as your documentation configuration files directory?\n(Y)es/(N)o?: ',word,strrep(confdir,'\','\\'));
            ds = lower(input(str,'s'));
            if isequal(ds,'n')
                d = uigetdir(confdir,'Please select the documentation configuration directory');
                if d == 0
                    error('No documentation configuration directory specified. Aborting setup.');
                end
                confdir = d;
            end
            setpref(MatlabDocMaker.getProjPrefTag,'confdir',confdir);
            
            % Output directory
            outdir = getpref(MatlabDocMaker.getProjPrefTag,'outdir',[]);
            word = 'keep';
            if isempty(outdir)
                outdir = confdir;
                word = 'set';
            end
            str = sprintf('Do you want to %s %s as your documentation output directory?\n(Y)es/(N)o?: ',word,strrep(outdir,'\','\\'));
            ds = lower(input(str,'s'));
            if isequal(ds,'n')
                d = uigetdir(outdir,'Please select the documentation output directory');
                if d == 0
                    error('No documentation output directory specified. Aborting setup.');
                end
                outdir = d;
            end
            setpref(MatlabDocMaker.getProjPrefTag,'outdir',outdir);
            
            %% Check for necessary and recommended tools
            hasall = true;
            setenv('PATH',[getenv('PATH') pathsep confdir]);
            fprintf('[Required] Checking for doxygen... ');
            [st, vers] = system('doxygen --version');
            if st == 0
                fprintf(' found %s\n',vers(1:end-1));
            else
                fprintf(2,' not found!\n');
                hasall = false;                
            end
            fprintf('[Required] Checking for mtoc++... ');
            [st, vers] = system('mtocpp --version');
            if st == 0
                fprintf(' found %s\n',vers(1:end-1));
            else
                fprintf(2,' not found!\n');
                hasall = false;
            end
            fprintf('[Required] Checking for m4... ');
            [st, vers] = system('m4 --version');
            if st == 0
                fprintf(' found %s\n',vers(1:18));
            else
                fprintf(2,' not found!\n');
                hasall = false;
            end
            fprintf('[Recommended] Checking for dot... ');
            [st, vers] = system('dot -V');
            if st == 0
                fprintf(' found %s\n',vers(1:end-1));
            else
                fprintf(2,'dot Graphviz tool not found!\nSet HAVE_DOT = NO in Doxyfile.m4 or install dot for nice diagrams.\n');
            end
            fprintf('[Recommended] Checking for latex... ');
            [st, vers] = system('latex --version');
            if st == 0
                fprintf(' found %s\n',vers(1:strfind(vers,sprintf('\n'))-1));
            else
                fprintf(2,'latex not found!\nA LaTeX installation available on the system path is strongly recommended with mtoc++.\n');
            end

            if ~hasall
                fprintf(2,'Please make sure all prerequisites can be found on PATH or copy the executables into %s.\n',confdir);
                fprintf('<<<< MatlabDocMaker setup finished with warnings. >>>>\n');
            else
                fprintf('<<<< MatlabDocMaker setup successful. >>>>\nYou can now create your projects documentation by running <a href="matlab:MatlabDocMaker.create(true)">MatlabDocMaker.create</a>!\n');
            end
        end
    end
    
    methods(Static, Access=private)
        function value = getProjPrefTag
            str = MatlabDocMaker.getProjectName;
            value = ['MTOCPP_' str(regexp(str,'[a-zA-z0-9]'))];
        end
    end
end
