import java.util.*;
public class A13
{
	Scanner scan=new Scanner(System.in);
	
	String model_no;
	int size;
	int price;
	
	public void get()
	{
		try
		{
		System.out.print("ENTER MODEL NUMBER: ");
		model_no=scan.next();
		if(model_no.length()>4)
		throw new Myexception("INVALID MODEL NUMBER!!");
		System.out.print("ENTER SIZE OF MODEL: ");
		size=scan.nextInt();
		if(size<4 || size>15)
		throw new Myexception("INVALID SIZE!!");
		System.out.print("ENTER COST: ");
		price=scan.nextInt();
		if(price>10000)
		throw new Myexception("INVALID COST!!");
		
		System.out.println("ENTRIES ACCEPTED!!");
		}
	catch(Myexception e)
	{
		System.out.println(e);
	}
	}
	public static void main(String []args)
	{
		a q=new a();
		q.get();
	}
	
}
