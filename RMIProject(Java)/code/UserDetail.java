package code;

import java.io.Serializable;


/**
 *
 * @author Mairéad and Martin
 */
public class UserDetail implements Serializable
{
    private String username;
    private String password;
  
    

    public UserDetail(String username, String password)
    {
        this.username = username;
        this.password = password;
    }

    public String getUsername()
    {
        return username;
    }

    public String getPassword()
    {
        return password;
    }

    public boolean equals(Object o)
    {
        UserDetail u = (UserDetail) o;
        if(this.username.equals(u.getUsername()) && this.password.equals(u.getPassword()))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}