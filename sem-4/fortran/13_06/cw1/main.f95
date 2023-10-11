program main
    implicit none
    real, parameter :: initialAmount = 1000
    integer, parameter :: years = 30
    real, parameter :: interestRate = 0.02

    real :: finalAmount
    integer :: i

    finalAmount = initialAmount

    do i = 1, years
        finalAmount = finalAmount + finalAmount * interestRate
    end do

    print *, "Final sum of deposit: ", finalAmount
    
end program main