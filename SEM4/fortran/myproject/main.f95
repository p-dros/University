module GraphModule
    implicit none

    public :: Graph
    public :: addEdge, DFS, hasEdge
    private :: DFS_visit

    type :: Graph
        integer, allocatable :: adjacencyMatrix(:, :)
        integer :: numVertices
    end type Graph

    contains
        subroutine addEdge(g, src, dest)
            type(Graph), intent(inout) :: g
            integer, intent(in) :: src, dest
            
            g%adjacencyMatrix(src, dest) = 1
            ! g%adjacencyMatrix(dest, src) = 1 - add then directed graph
        end subroutine addEdge

        function hasEdge(g, src, dest) result(result)
            logical :: result
            type(Graph), intent(inout) :: g
            integer, intent(in) :: src, dest

            result = .false.
            if (g%adjacencyMatrix(src, dest) == 1) then
                result = .true.
            end if
        end function hasEdge
        
        subroutine removeEdge(g, src, dest)
            type(Graph), intent(inout) :: g
            integer, intent(in) :: src, dest

            if (g%adjacencyMatrix(src, dest) == 1) then
                g%adjacencyMatrix(src, dest) = 0
            end if
        end subroutine removeEdge

        recursive subroutine DFS(g, source)
            type(Graph), intent(inout) :: g
            integer, intent(in) :: source
            logical :: visited(g%numVertices)

            visited = .false.

            write(*, '(A, I0, A)') "DFS traversal starting from vertex ", source, ": "
            call DFS_visit(g, source, visited)
            write(*, *) 
        end subroutine DFS

        recursive subroutine DFS_visit(g, index, visited)
            type(Graph), intent(inout) :: g
            integer, intent(in) :: index
            logical, intent(inout) :: visited(:)
            integer :: i

            visited(index) = .true.
            write(*, '(I0, A)', advance='no') index, " "

            do i = 1, g%numVertices
                if (g%adjacencyMatrix(index, i) == 1 .and. .not. visited(i)) then
                    call DFS_visit(g, i, visited)
                end if
            end do
        end subroutine DFS_visit

        function inConnections(g, vertexIdx) result(connections)
            type(Graph), intent(in) :: g
            integer, intent(in) :: vertexIdx
            integer :: i
            logical :: isValidIndex
            integer, dimension(g%numVertices) :: connections

            isValidIndex = vertexIdx >= 1 .and. vertexIdx <= g%numVertices

            if (.not. isValidIndex) then
                write(*,*) "Index out of bounds"
                stop
            end if

            connections = 0

            do i = 1, g%numVertices
                if (g%adjacencyMatrix(i, vertexIdx) == 1) then
                    connections(i) = 1
                end if
            end do
        end function inConnections

        function outConnections(g, vertexIdx) result(connections)
            type(Graph), intent(in) :: g
            integer, intent(in) :: vertexIdx
            integer :: i
            logical :: isValidIndex
            integer, dimension(g%numVertices) :: connections

            isValidIndex = vertexIdx >= 1 .and. vertexIdx <= g%numVertices

            if (.not. isValidIndex) then
                write(*,*) "Index out of bounds"
                stop
            end if

            connections = 0

            do i = 1, g%numVertices
                if (g%adjacencyMatrix(vertexIdx, i) == 1) then
                    connections(i) = 1
                end if
            end do
        end function outConnections
end module GraphModule

program GraphImplementation 
    use GraphModule
    implicit none

    type(Graph) :: myGraph
    integer :: numVertices, numEdges
    integer :: i, src, dest
    logical, allocatable :: visited(:)

    write(*,*) "Enter the number of vertices:"
    read(*,*) numVertices
    write(*,*) "Enter the number of edges:"
    read(*,*) numEdges

    allocate(myGraph%adjacencyMatrix(numVertices, numVertices))
    myGraph%numVertices = numVertices
    myGraph%adjacencyMatrix = 0

    do i = 1, numEdges
        write(*,*) "Enter source and destination vertex for edge ", i
        read(*,*) src, dest
        call addEdge(myGraph, src, dest)
    end do

    allocate(visited(numVertices))
    visited = .false.

    write(*,*) "Enter Index from which you want to perform DFS:"
    read (*,*) i
    call DFS(myGraph, i)

    deallocate(myGraph%adjacencyMatrix)
    deallocate(visited)
end program GraphImplementation