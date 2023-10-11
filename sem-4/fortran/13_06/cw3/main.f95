program p33
    implicit none
    integer, parameter :: rdp=SELECTED_REAL_KIND(15)
    integer, parameter :: idp=SELECTED_INT_KIND(15)
    real(KIND=rdp) :: xx
    integer(KIND=idp) :: i
    integer, parameter :: max_do=2000000_idp
    
    real(KIND=rdp), parameter :: xp = 0 
    real(KIND=rdp), parameter :: xk = 3.14159265358979323846264338327950288_rdp
    real(KIND=rdp) :: integral 
    real(kind=rdp) :: dx

    integral = 0
    dx = xk - xp

    CALL init_random_seed()
    do i=1, max_do
        call random_number(xx)
        integral = integral + sin((xp + xx * dx))        
    end do
    integral = dx * integral / real(max_do)
    
    print *, "Wartosc calki wynosi: ", integral

    stop
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
end program p33