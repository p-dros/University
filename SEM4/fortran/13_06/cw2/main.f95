program main
    implicit none
    
    integer, parameter :: rdp = selected_int_kind(15)
    integer(rdp), parameter :: N1 = 9
    integer(rdp), parameter :: N2 = 10

    integer(rdp) :: suma

    suma = recursiveSum(N1, N2)

    write(*, '(A, I0, A, I0, A, I0)') "Suma liczb od ", N1, " do ", N2, " wynosi: ", suma

    contains 
    recursive function recursiveSum(m, n) result(suma)
        integer(rdp), intent(in) :: m, n
        integer(rdp) :: suma

        if (m == n) then
            suma = m
        else 
            suma = m + recursiveSum(m + 1, n)
        end if
    end function recursiveSum
end program main