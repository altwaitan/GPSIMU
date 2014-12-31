# Author: Abdullah Altawaitan
# Date: 4 November 2014

# Sets the compilation flags to report all warnings and enable debugging in the generated
# object files and executable.

set( CMAKE_C_FLAGS "-Wall -g" )

# The following file GLOB command will search for all files within the current directory
# that match the specified expressions (*.cpp and *.h), and assign the resulting files
# to the variable SRCS. Thus, SRCS is a list a all C source and header files in the 
# current directory.

file( GLOB SRCS *.cpp *.h )

# Define the target application executable (named spacer) and the list of C source
# and header files needed for the executable.

add_executable( gpsimu ${SRCS} )
