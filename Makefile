a.out: main.o CustomerList.o OrderList.o
	gcc main.o CustomerList.o OrderList.o -o a.out

main.o: main.c
	gcc -c main.c

CustomerList.o: CustomerList.c
	gcc -c CustomerList.c

OrderList.o: OrderList.c
	gcc -c OrderList.c

clean:
	rm -rf *o a.out