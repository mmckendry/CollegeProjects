package code;

import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.Registry;
import java.rmi.registry.LocateRegistry;
import java.net.*;
import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

/**
 *
 * @author Mairéad & Martin
 */
public class Server 
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);
        int portNum = 22517;
        String registryURL;

        try
        {
            startRegistry(portNum);

                    
            
            ArrayList<UserDetail> users = new ArrayList<UserDetail>();
            UserDetail u1 = new UserDetail("u1", "1234");
            users.add(u1);
            
            Impl exportedObj = new Impl(users);
            
            // Register the polling object with the directory
            registryURL = "rmi://localhost:" + portNum + "/poll";
            Naming.rebind(registryURL, exportedObj);
            System.out.println("Server registered.  Registry currently contains:");
            // list names currently in the registry
            listRegistry(registryURL);

            System.out.println("Poll Server ready.");
        }// end try
        catch (Exception re)
        {
            System.out.println("Exception in PollServer.main: " + re);
        } // end catch
    } // end main

    // This method starts a RMI registry on the local host, 
    // if it does not already exists at the specified port number.
    private static void startRegistry(int RMIPortNum) throws RemoteException
    {
        try
        {
            Registry registry = LocateRegistry.getRegistry(RMIPortNum);
            registry.list();  // This call will throw an exception if the registry does not already exist
        }
        catch (RemoteException e)
        {
            // No valid registry at that port.
            System.out.println("RMI registry cannot be located at port " + RMIPortNum);
            Registry registry = LocateRegistry.createRegistry(RMIPortNum);
            System.out.println("RMI registry created at port " + RMIPortNum);
        }
    } // end startRegistry

    // This method lists the names registered with a Registry object
    private static void listRegistry(String registryURL) throws RemoteException, MalformedURLException
    {
        System.out.println("Registry " + registryURL + " contains: ");
        String  names[] = Naming.list(registryURL);

        for (int i=0; i < names.length; i++)
        {
            System.out.println(names[i]);
        }
    } //end listRegistry

} // end class