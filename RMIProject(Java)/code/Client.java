package code;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.Scanner;

/**
 *
 * @author Mairéad & Martin
 */
public class Client 
{
    private static Interface service;
    private static Scanner input;

    public static void main(String args[])
    {
        try
        {
            input = new Scanner(System.in);
            
            // Set up the directory service details
            String hostName = "localhost";
            int RMIPort = 22517;

            String registryURL = "rmi://" + hostName + ":" + RMIPort + "/poll";
            // find the remote object and cast it to an interface object
            service = (Interface)Naming.lookup(registryURL);
            System.out.println("Lookup completed ");
            
            // Create a Client object for use in callbacks            
            ClientImpl clientObj = new ClientImpl();
            // Register the client object for callbacks
            service.registerForCallback(clientObj);

            String answer = "y";
            while(!answer.equalsIgnoreCase("n"))
            {
                System.out.println("Please enter an option to perform:");
                System.out.println("1) Log in.");
                System.out.println("2) Register.");
                
                int selection = input.nextInt();
                input.nextLine();
                
                if(selection == 1)
                {
                    login();
                }
                else if(selection == 2)
                {
                    register();
                }
                else
                {
                    System.out.println("Invalid selection.");
                }
                
                System.out.println("Do you wish to continue? (y/n)");
                answer = input.nextLine();
            }
            // Added for callback
            // Must remember to unregister the client before the end of the program is reached
            service.unregisterForCallback(clientObj);
            // Unexport the Client object - this is required to ensure that the program will terminate
            UnicastRemoteObject.unexportObject(clientObj, true);
            
            System.out.println("Thank you for your using this service. Goodbye.");
        } // end try
        catch (Exception e)
        {
            System.out.println("Exception in Client" + e);
            e.printStackTrace();
        }
    } //end main

    public static void login() throws java.rmi.RemoteException, IOException
    {
        System.out.println("Please enter your username:");
        String username = input.nextLine();
        System.out.println("Please enter your password:");
        String password = input.nextLine();
        
        UserDetail user = new UserDetail(username, password);
        
        if(service.login(user))
        {
            System.out.println("Login successful.");
            displayMainMenu();
        }
        else
        {
            System.out.println("Login failed.");
        }
    }
    
   public static void register() throws java.rmi.RemoteException
   {
        System.out.println("\t****Welcome, please enter your details below****");
        System.out.println("Please enter your username:");
        String username = input.nextLine();
        System.out.println("Please enter your password:");
        String password = input.nextLine();
        
        UserDetail user = new UserDetail(username, password);
        if(service.register(user))
        {
            System.out.println("Registration successful.");
        }
        else
        {
            System.out.println("Registration failed.");
        }
   }
   
   public static void displayMainMenu() throws RemoteException, IOException{
       String answer = "y";
            while(!answer.equalsIgnoreCase("n"))
            {
                System.out.println("Please enter an option to perform:");
                System.out.println("1) Display all members.");
                System.out.println("2) Display active members.");
                System.out.println("3) Send single message.");
                System.out.println("4) Send group message.");
                
                int selection = input.nextInt();
                input.nextLine();
                
                if(selection == 1)
                {
                    listUsers();
                }
                else if(selection == 2)
                {
                    //listActiveUsers();
                }
                else if(selection == 3)
                {
                    sendSingleMessage();
                }
                else if(selection == 4)
                {
                    //sendGroupMessage();
                }
                else
                {
                    System.out.println("Invalid selection.");
                }
                
                System.out.println("Do you wish to continue? (y/n)");
                answer = input.nextLine();
            }
            
   }
   
   public static void listUsers()throws java.rmi.RemoteException{
       service.listAllUsers();
   }
   
   
   public static void sendSingleMessage()throws java.rmi.RemoteException, IOException{
        InputStreamReader is = new InputStreamReader(System.in);
       BufferedReader br = new BufferedReader(is);
       
       System.out.println("Please enter the message you wish to send:  ");
      String message = br.readLine(); 
       
       service.sendSingleMessage(message);
       
   }
   
}
