import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

/*
Guide to the Errors that can be caused 
Port number binding exception 
netstat -ano | findstr :17
taskkill /pid yourid /f
this only works for windows 
for further reference refer to: https://stackoverflow.com/questions/12737293/how-do-i-resolve-the-java-net-bindexception-address-already-in-use-jvm-bind


*/

public class Rfc865UdpServer {
    static  DatagramSocket socket;
    static int PORT = 17;
 public static void main(String[] argv) {
 //
 // 1. Open UDP socket at well-known port
 //

 try {
 socket = new DatagramSocket(PORT);
 System.out.println("Socket Created...");
 } catch (SocketException e) {
    System.err.println("Failed to create Datagram Socket.");
    e.printStackTrace();
 }
 while (true) {
     System.out.println("Waiting...");
 try {
 //
 // 2. Listen for UDP request from client
 //
	 InetAddress ip = InetAddress.getByName("localhost");
	 byte buf[]=new byte[512];
     DatagramPacket request = new DatagramPacket(buf, buf.length);
     socket.receive(request);
     String sentence = new String(request.getData());
     System.out.println("RECEIVED: " + sentence);

     
 //
 // 3. Send UDP reply to client
 //
    String inp = new String("Random");
    byte buf2[]=inp.getBytes();
    int port = request.getPort();
    InetAddress address = request.getAddress();
     DatagramPacket reply = new DatagramPacket(buf2, buf2.length, address, port);
     socket.send(reply);
 } catch (IOException e) {}
 }
 }
}