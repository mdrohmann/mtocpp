classdef classA < general.reference.classB & a.b.c & ...
    d.e.f ...
    & g.h.i;
  % help for classA
  %
  % bigger help for classA

  properties ( SetAccess = private, GetAccess = protected, Transient);% garbage comment

    mixed_access; % of type gridbase short help

    % longer help with `default` value
    % what is this??
    %
    % can we do some special stuff??
    % @verbatim
    %  a= b;
    %  c= d;
    % @endverbatim
    mixed_access2 = 'test';


  end; % garbage comment

  properties (Constant); % garbage comment
    aConstant = 1; % help text

    % help text for bConstant
    bConstant = 2;

    cConstant = 3; % help text for cConstant
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

      bar;
    end; % garbage comment

    % comment
    %  zweite Zeile

    function obj = bar(c,d,e);
      % brief doc for bar

      foo;
    end;

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
      % setter enriching property help text of protected_access

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
    [a] = abstract_method(this,d,e); % an abstract comment behind
    % an abstract method comment below
  end

  events
  end

end

