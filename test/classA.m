classdef(Sealed=Initialize) classA < general.reference.classB & a.b.c & ...
    d.e.f ...
    & g.h.i ...
    & grid.rect.rectgrid;
  % help for classA
  %
  % bigger help for classA

  properties ( SetAccess = private, GetAccess = protected, Transient);% garbage comment

    mixed_access; % variable of type gridbase.gridbase storing a grid.

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

    SomeProp = struct('xi',[],'ti',[],'mui',[]);

  end; % garbage comment

  properties (Constant); % garbage comment
    aConstant = 1; % help text

    % help text for bConstant
    bConstant = 2;

    cConstant = 3; % help text for cConstant

    % test
    dConstant = { [ 1, 2; 3, 4]; 'test'; [ 1 2; [ [3 [3 [3 4] 4] ] ] ] };

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

  methods(Hidden = True); % garbage comment

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

    function ret = test(auto_param,b,c)
      % @copybrief grid::rect::rectgrid::test()
      %
      % If copydetails/copydoc commands are used, "parameters" and "return
      % values" are ignored in the derived class, except for the strings
      % 'object of ...' which are used to define the parameter / return value
      % type.
      %
      % @copydetails grid::rect::rectgrid::test()
      %
      % Parameters:
      %   b: second argument in derived class (this is not shown!)
      %   c: object of type test2
    end
  end

  methods (Static, Abstract)
    % a static abstract method
    [a,b] = static_abstract_method(this, c);

  end

  methods (Abstract)

    % an abstract method comment above
    %
    % Parameters:
    %  d:  parameter 1
    %  e:  parameter 2
    %
    % Return values:
    %   a: test of type classA::mixed_access
    [a] = abstract_method(this,d,e);
    % an abstract method comment below
    %
    % further comments
  end

  events
  end

end

