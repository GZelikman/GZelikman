import socket               # Import socket module
import timeit

s = socket.socket()         # Create a socket object
host = "192.168.0.130" # Get local machine name
port = 13370                 # Reserve a port for your service.
data = "Hello server!Hello server!Hello server!Hello server!Hello server!Hello server!Hello server!Hello server!Hello server!Hello server!Hello server!Hello server!Hello server!Hello server!Hello server!"

s.connect(("192.168.0.130", port))
start = timeit.timeit()
s.send(data.encode())
print ('Sending...')
print ("Done Sending")
end = timeit.timeit()
print (s.recv(1024).decode())
print(end - start) 
s.close 