package code;

import java.rmi.*;
import java.rmi.server.*;

/**
 *
 * @author Mairéad & Martin
 */
public class ClientImpl extends UnicastRemoteObject implements ClientInterface
{
    public ClientImpl() throws java.rmi.RemoteException
    {
        super();
    }
    
    public void notifyMe(String message) throws java.rmi.RemoteException
    {
        String returnMessage = "Call back received: " + message;
        System.out.println(returnMessage);
    }
    
}
