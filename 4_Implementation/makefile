PROJECT_NAME = main.exe

SRC = main.c\
src\file_creation.c\
src\insertion.c\
src\bubble.c\
src\selection_run.c\
src\Merge_sort.c\



INC = inc

ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

$(PROJECT_NAME): $(SRC)
	gcc -I $(INC) $(SRC) -o main.exe
	
run: $(PROJECT_NAME)
	$(PROJECT_NAME)
	
clean:
	del /q *.exe