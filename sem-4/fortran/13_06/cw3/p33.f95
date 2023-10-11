PROGRAM p33
    IMPLICIT NONE
    INTEGER, PARAMETER :: rdp=SELECTED_REAL_KIND(15)
    INTEGER, PARAMETER :: idp=SELECTED_INT_KIND(15)
    REAL(KIND=rdp) :: xx, yy, rr, pi_moje, delta
    REAL(KIND=rdp) :: pi=3.14159265358979323846264338327950288_rdp
    REAL :: x
    INTEGER(KIND=idp) :: i,wewnatrz
    INTEGER, PARAMETER :: max_do=1000000_idp

    CALL init_random_seed()
    wewnatrz=0
    do i=1, max_do
        CALL RANDOM_NUMBER(xx)
        CALL RANDOM_NUMBER(yy)
        rr=xx*xx + yy*yy

        if (rr <= 1.0_rdp) wewnatrz=wewnatrz+1
    END DO

    pi_moje = REAL(wewnatrz)/REAL(max_do)*4.0_rdp
    delta=ABS((pi-pi_moje)/pi)
    PRINT *
    PRINT *, "pi_moje = ", pi_moje, "blad wzgledny = ", delta
    STOP
    CONTAINS
        SUBROUTINE init_random_seed()
            INTEGER :: i,n,clock
            INTEGER, DIMENSION(:), ALLOCATABLE :: seed

            CALL RANDOM_SEED(SIZE=n)
            PRINT *, "SIZE = ", n
            ALLOCATE(seed(n))

            CALL SYSTEM_CLOCK(COUNT=clock)
            PRINT *, "CLOCK = ", clock

            seed = clock + 37 * (/(i - 1, i = 1, n)/)
            CALL RANDOM_SEED(PUT = seed)

            DEALLOCATE(seed)
        END SUBROUTINE
END PROGRAM p33