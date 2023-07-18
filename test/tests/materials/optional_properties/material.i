[Mesh]
  [gen]
    type = GeneratedMeshGenerator
    dim = 2
    nx = 10
    ny = 10
  []
  [block1]
    type = SubdomainBoundingBoxGenerator
    input = gen
    bottom_left = '0 0 0'
    top_right = '0.5 1.0 1.0'
    block_id = 1
  []
[]

[Problem]
  solve = false
[]

[Materials]
  [before]
    type = OptionalTestMaterial
    prop = prop
    adprop = adprop
    expect = true
    adexpect = true
    outputs = exodus
  []

  [prop]
    type = GenericFunctionMaterial
    prop_names = prop
    prop_values = t+1+x
  []
  [adprop]
    type = ADGenericFunctionMaterial
    prop_names = adprop
    prop_values = t+10+y
  []

  [after0]
    type = OptionalTestMaterial
    block = 0
    prop = prop
    adprop = adprop
    expect = true
    adexpect = true
    outputs = exodus
  []
  [after1]
    type = OptionalTestMaterial
    block = 1
    prop = prop
    adprop = adprop
    expect = true
    adexpect = true
    outputs = exodus
  []
[]

[Executioner]
  type = Transient
  num_steps = 4
[]

[Outputs]
  exodus = true
[]
