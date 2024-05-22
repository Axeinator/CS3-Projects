public class Ship
{
    private int row, col, length, direction;
    
    // Direction constants
    public static final int UNSET = -1;
    public static final int HORIZONTAL = 0;
    public static final int VERTICAL = 1;
    
    public Ship(int length) {
        this.length = length;
    }
    
    public boolean isLocationSet() {
        return row >= 0 && col >= 0;
    }
    public boolean isDirectionSet() {
        return direction != -1;
    }
    public void setLocation(int row, int col) {
        this.row = row;
        this.col = col;
    }
    public void setDirection(int direction) {
        this.direction = direction;
    }
    public int getRow() {
        return row;
    }
    public int getCol() {
        return col;
    }
    public int getLength() {
        return length;
    }
    public int getDirection() {
        return direction;
    }
    private String directionToString() { return "";}
    public String toString() { return "";}
        
}
