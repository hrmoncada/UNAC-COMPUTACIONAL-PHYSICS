MODULE INIT_MOD
  USE, INTRINSIC :: ISO_C_BINDING, ONLY: C_INT
  IMPLICIT NONE
  INTEGER(C_INT), BIND(C, NAME='f_init_g') :: f_init_g(3)
END MODULE INIT_MOD
