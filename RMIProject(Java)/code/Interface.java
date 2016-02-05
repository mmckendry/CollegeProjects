package code;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.ArrayList;

/**
 *
 * @author Mairéad & Martin
 */

public interface Interface extends Remote
{
   
    public boolean login(UserDetail u1) throws RemoteException;
    public boolean register(UserDetail u1) throws RemoteException;
    public void listAllUsers() throws RemoteException;
    
    // Added for callback
    
    // This remote method allows an object client to register for callback
    public void registerForCallback(ClientInterface clientObj) throws java.rmi.RemoteException;
    // This remote method allows an object client to cancel its registration for callback
    public void unregisterForCallback(ClientInterface clientObj) throws java.rmi.RemoteException;

    public void sendSingleMessage(String message)throws java.rmi.RemoteException;


   
}
