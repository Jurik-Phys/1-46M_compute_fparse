EXEC=fparse
EXEC_T=t_$(EXEC)
OBJ=fparse.o main.o
OBJ_T=fparse.o test.o 

main:$(OBJ)
	@echo 'Сборка исполняемого файла'
	c++ -Wall -o $(EXEC) $(OBJ)
main.o: main.c++ 
	@echo "Компиляция main.c++"
	c++ -Wall -c main.c++ 
fparse.o: fparse.c++
	@echo "Компиляция fparse.c++"
	c++ -Wall -c fparse.c++
clean:
	@echo "Удаление объектных файлов"
	rm -f *.o
run:$(EXEC)
	./$(EXEC)
test.o: test.c++
	@echo "Компиляция UNIT тестов" 
	c++ -Wall -c test.c++
test: $(OBJ_T)
	c++ -Wall -o $(EXEC_T) $(OBJ_T) 
	
