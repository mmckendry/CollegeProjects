package code;

/**
 *
 * @author Mairéad & Martin
 */
public interface ClientInterface extends java.rmi.Remote
{
    public void notifyMe(String message) throws java.rmi.RemoteException;
}
