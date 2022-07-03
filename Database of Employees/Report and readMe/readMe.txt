To run the program make sure all the following files are in the same folder:
	
	History.c
	Manager.c
	Server.c
	SocketConnection.c
	ID_Name.txt
	Salaries.txt
	SatisfactionLevel.txt
	

Open two terminals and set them to the same working directory

Compile the program using the following format:

	gcc SocketConnection.c Server.c History.c -o Server.out

	gcc Manager.c -o Client.out
	
In terminal one open Server.out using the following format:

	./Server.out 4547

This will open up the server and it will wait for the client to enter something

Assuming you are in the same computer:
In terminal number two open Client.out using the following format: 
	
	./Client.out localhost 4547

Then follow the instructions on terminal number 2.

