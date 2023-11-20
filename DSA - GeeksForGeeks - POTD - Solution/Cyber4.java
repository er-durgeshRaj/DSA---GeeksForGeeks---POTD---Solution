import java.io.*;
import java.net.*;
class Cyber4
{
public static void main(String args[]) throws IOException
{
System.out.println("\nGanesh Kumar 211061101120\n");
ServerSocket ss=new ServerSocket(7777);
Socket s=ss.accept();
System.out.println("connected...");
FileInputStream fin=new FileInputStream("D:\\send.txt");
DataOutputStream dout=new DataOutputStream(s.getOutputStream());
int r;
while((r=fin.read())!=-1)
{
dout.write(r);
}
System.out.println("\nFile transfer completed");
s.close();
ss.close();
}
}