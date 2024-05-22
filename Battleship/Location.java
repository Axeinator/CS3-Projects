public class Location
{
    public static final int UNGUESSED = 0;
    public static final int HIT = 1;
    public static final int MISSED = 2;
    
    //Implement the Location class here
    private int status;
    private boolean ship;
    
    public Location() {
        status = 0; 
        ship = false;
    }
    public boolean checkHit() {
        return status == 1;
    }
    public boolean checkMiss() {
        return status == 2;
    }
    public boolean isUnguessed() {
        return status == 0;
    }
    public void markHit() {
        status = 1;
    }
    public void markMiss() {
        status = 2;
    }
    public boolean hasShip() {
        return ship;
    }
    public void setShip(boolean val) {
        ship = true;
    }
    public void setStatus(int status) {
        this.status = status;
    }
    public int getStatus() {
        return status;
    }
}
