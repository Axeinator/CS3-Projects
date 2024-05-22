import java.util.*;

public class Player
{
    // Write your Player class here
    private static final int[] SHIP_LENGTHS = {2, 3, 3, 4, 5};
    
    private ArrayList<Ship> ships;
    private Grid ownGrid;
    private Grid opponentGrid;
    
    public Player() {
        ships = new ArrayList<Ship>();
        for (int length : SHIP_LENGTHS) {
            ships.add(new Ship(length));
        }
        ownGrid = new Grid();
        opponentGrid = new Grid();
    }
    
    public void chooseShipLocation(Ship s, int row, int col, int direction) {
        s.setLocation(row, col);
        s.setDirection(direction);
        ownGrid.addShip(s);
    }
    public ArrayList<Ship> getShips() {
        return ships;
    }
    public Grid getOwnGrid() {
        return ownGrid;
    }
    public Grid getOpponentGrid() {
        return opponentGrid;
    }
    
}
