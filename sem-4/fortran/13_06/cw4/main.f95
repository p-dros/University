program findRoots
    implicit none
    integer, parameter :: points = 7000
    real, parameter :: start = -3.0
    real, parameter :: end = 4.0
    real, parameter :: step = 0.001
    real, parameter :: areaSize = (end - start) / real(points)

    real :: x, y, y_prev
    real :: areaStart, areaEnd

    areaStart = start
    areaEnd = start + areaSize

    x = start

    y_prev = f(x)

    do while (x <= end)
        x = x + step
        y = f(x)
        if (y * y_prev < 0.0) then
            print *, "Root has been found in the area: "
            print *, "x_1 =", x - step
            print *, "x_2 =", x
        end if

        if (x >= areaEnd) then
            areaStart = areaEnd
            areaEnd = areaEnd + areaSize
            y_prev = f(areaStart)
        else
            y_prev = y
        end if
    end do

contains

    function f(x) result(result)
        real, intent(in) :: x
        real :: result

        result = x**3 - 3.0 * x**2 - 4.0 * x + 12.0
    end function f

end program findRoots
