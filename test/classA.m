classdef classA < general.reference.classB & a.b.c & ...
    d.e.f ...
    & g.h.i;
  % help for classA
  %
  % bigger help for classA

  properties ( SetAccess = private, GetAccess = protected, Transient);% garbage comment

    mixed_access; % of type gridbase.gridbase short help

    % longer help with `default` value
    % what is this??
    %
    % can we do some special stuff??
    % @verbatim
    %  a= b;
    %  c= d;
    % @endverbatim
    mixed_access2 = 'test';

    DataStoreDirectory = '';

  end; % garbage comment

  properties (Constant); % garbage comment
    aConstant = 1; % help text

    % help text for bConstant
    bConstant = 2;

    cConstant = 3; % help text for cConstant

    dConstant = struct('a', [], 'b', {'c', 'd'}, 'e', [1 2 3]);
  end

  properties
    public_access; % short help for public_access

    % longer help for public_access2
    public_access2;
  end

  properties (Access = protected)
    protected_access; % short help for protected_access

    % longer help text for protected_access2
    protected_access2;
  end

  methods; % garbage comment

    function obj = foo(a,b,c);
      % brief doc for foo

      function private_function

        pause;
      end

      bar;
    end; % garbage comment

    % comment
    %  zweite Zeile

    function obj = bar(c,d,e);
      % brief doc for bar

      foo;
    end;

    % last function comment above
    %
    % with main docu block
    function obj = foobar()
    % brief for foobar
    %
    % detail for foobar

     test

    end %garbage comment

    % this is only a declaration without definition of a method
    ret=mdecl(a,b);;;;;;;;
    % this is only a declaration without definition of a method behind

    function obj = classA(param1, param2)
      % bigger constructor
    end;
  end; %garbage comment

  methods
    function value = get.protected_access(this)
      % getter enriching property help text of protected_access

      if a==b
        do something;
      % the following end needs to be indented correctly
      end % garble this correctly
%|
% \todo this is a test

    end

    function set.protected_access(this, value)
      % setter comment is parsed too

      a;
    end


    function set.DataStoreDirectory(this, ds)
      if ~isdir(ds)
        fprintf('Creating directory %s\n',ds);
        mkdir(ds);
      end
      setpref('KERMOR','DATASTORE',ds);
      this.DataStoreDirectory = ds;
      fprintf('Simulation and model data: %s\n',ds);
    end

    function set.protected_access2(this, value)

       a;
    end

  end

  methods (Static) ;;; % garbage comment
    function [a,b] = static_method(notthis,c)
      % a static method
    end
  end

  methods (Abstract)
    % an abstract method comment above
    %
    [a] = abstract_method(this,d,e);
    % an abstract method comment below
    %
    % Return values:
    %   a: test of type @link classA::mixed_access "gridbase comment" @endlink
    % an abstract method comment below
  end

  events
  end

end

