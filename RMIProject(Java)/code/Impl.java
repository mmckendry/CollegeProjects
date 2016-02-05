package code;

import java.rmi.*;
import java.rmi.server.*;
import java.io.* ;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Mairéad & Martin
 */
public class Impl extends UnicastRemoteObject implements Interface
{
    //private String issue;
    //private HashMap<String, Integer> options;
    private ArrayList<UserDetail> users;
    // Added for callback
    private ArrayList<ClientInterface> clientList;

    // constructor
    public Impl(ArrayList<UserDetail> users) throws RemoteException
    {
        super();

        
        this.users = users;
        
        clientList = new ArrayList<ClientInterface>();
    }
    
   
    
    public boolean login(UserDetail u1) throws RemoteException
    {
        if(users.contains(u1))
            return true;
        else
            return false;
    }
    
   public boolean register(UserDetail user)throws RemoteException
    {
        for(UserDetail u: users)
        {
            if(user == u)
            {
                return false;
            }
            else
            {
                users.add(user);
                return true;
            }
        }
        return false;
             
    }

   public void listAllUsers()throws RemoteException{
       for(UserDetail u: users)
           System.out.println(u);
   }
    // Added for callback
    
   
   
   //sending a single message
   
    
   
   public void sendSingleMessage(String message)throws RemoteException{
       
     
        System.out.println(message);
       
   }
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   // Method to register clients for callback purposes
    public synchronized void registerForCallback(ClientInterface clientObj) throws java.rmi.RemoteException
    {
        // Make sure that the client is not already there
        if(!clientList.contains(clientObj))
        {
            // Add the client to the list so they can get callback messages
            clientList.add(clientObj);
            System.out.println("Registered client ");
        }
        else
        {
            System.out.println("Register failed - client was already registered.");
        }
    }
    
    public synchronized void unregisterForCallback(ClientInterface clientObj) throws java.rmi.RemoteException
    {
        // Check if the client is actually there to remove
        if(clientList.contains(clientObj))
        {
            // Remove the client from the list so they don't get any more callback messages
            clientList.remove(clientObj);
            System.out.println("Unregistered client ");
        }
        else
        {
            System.out.println("unregister: clientwasn't registered.");
        }
    }
    
    public void doCallbacks() throws java.rmi.RemoteException
    {
        // make callback to each registered client
        System.out.println("**************************************\n" + "Callbacks initiated ---");

        for (int i = 0; i < clientList.size(); i++)
        {
            System.out.println("Doing "+ i+1 +"th callback\n");
            
            // Get each client object to callback & update them
            ClientInterface nextClient = (ClientInterface)clientList.get(i);
            
           
        }// end for

        System.out.println("********************************\n" + "Server completed callbacks ---");
    } // doCallbacks

    
   
    
} // end class