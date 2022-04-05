import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

public class Rfc865UdpClient {

 public static void main(String[] argv) {
 //
 // 1. Open UDP socket
 //
 DatagramSocket socket=null;
 try {
 socket = new DatagramSocket();
 } catch (SocketException e) {}

 try {
 //
 // 2. Send UDP request to server
 //  
	 
	 //InetAddress ip = InetAddress.getByName("swlab2-c.scse.ntu.edu.sg");
     InetAddress ip = InetAddress.getByName("localhost");
	 String inp = new String("Sankar Samiksha SS5"+ InetAddress.getByName("localhost"));
     byte buf[]=inp.getBytes();

     DatagramPacket request = new DatagramPacket(buf, buf.length,ip, 17);
     socket.send(request);

 //
 // 3. Receive UDP reply from server
 //
     //InetAddress ip = InetAddress.getByName("localhost");
	 byte buf2[]=new byte[512];
     DatagramPacket received = new DatagramPacket(buf2, buf2.length);
     socket.receive(received);
     String sentence = new String(received.getData());
     System.out.println("RECEIVED: " + sentence);
 }catch (Exception e) {}
}
}