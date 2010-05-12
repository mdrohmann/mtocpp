classdef classA < classB & classC
  % help for classA
  %
  % bigger help for classA

  properties (GetAccess = private, SetAccess = protected, Transient)

    mixed_access; % short help

    % longer help with default value
    mixed_access2 = 'test';
  end

  properties (Constant)
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

  methods
    function obj = classA
      % default constructor
    end

    function obj = classA(param1, param2)
      % bigger constructor
  end

  methods (Access = protected, Sealed)
    function value = get.protected_access(this)
      % getter enriching property help text of protected_access
    end

    function set.protected_access(this, value)
      % setter enriching property help text of protected_access
    end
  end

  methods (Static)
    function [a,b] = static_method(c)
      % a static method
    end
  end

  methods (Abstract)
    function [a] = abstract_method(d)
      % an abstract method
  end

  events
  end

end

