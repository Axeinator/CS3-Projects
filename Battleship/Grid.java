public class Grid
{
    // Write your Grid class here
    private Location[][] grid;
    public static final int NUM_ROWS = 10;
    public static final int NUM_COLS = 10;
    
    public Grid() {
        grid = new Location[NUM_ROWS][NUM_COLS];
        for (int i = 0; i < NUM_ROWS; i++) {
            for (int j = 0; j < NUM_COLS; j++) {
                grid[i][j] = new Location();
            }
        }
    }
    
    public void markHit(int row, int col) {
        grid[row][col].markHit();
    }
    public void markMiss(int row, int col) {
        grid[row][col].markMiss();
    }
    public void setStatus(int row, int col, int status) {
        grid[row][col].setStatus(status);
    }
    public int getStatus(int row, int col) {
        return grid[row][col].getStatus();
    }
    public boolean alreadyGuessed(int row, int col) {
        return !grid[row][col].isUnguessed();
    }
    public void setShip(int row, int col, boolean val) {
        grid[row][col].setShip(val);
    }
    public boolean hasShip(int row, int col) {
        return grid[row][col].hasShip();
    }
    public Location get(int row, int col) {
        return grid[row][col];
    }
    public int numRows() {
        return NUM_ROWS;
    }
    public int numCols() {
        return NUM_COLS;
    }
    public void printStatus() {
        System.out.println(" 1 2 3 4 5 6 7 8 9 10");
        String[] s = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
        for (int i = 0; i < 10; i++) {
            System.out.print(s[i] + " ");
            for(int j = 0; j < 10; j++) {
                if (grid[i][j].getStatus() == 0) System.out.print("- ");
                else if (grid[i][j].getStatus() == 1) System.out.print("X ");
                else System.out.print("0 ");
            }
            System.out.println();
        }
    }
    public boolean addShip(Ship s) {
        if (!s.isLocationSet() || !s.isDirectionSet()) {
            System.out.println("Location or direction not set. Invalid.");
            return false;
        }
        int row = s.getRow();
        int col = s.getCol();
        int length = s.getLength();
        int direction = s.getDirection();
        
        if ((direction == Ship.HORIZONTAL && col + length > NUM_COLS) || (direction == Ship.VERTICAL && row + length > NUM_ROWS)) {
            System.out.println("Ship doesn't fit within grid boundaries. ");
            return false;
        }
         
        for (int i = 0; i < length; i++) {
            if (direction == Ship.HORIZONTAL && grid[row][col + i].hasShip()) {
                System.out.println("Another ship obstructs the path.");
                return false;
            }
            if (direction == Ship.VERTICAL && grid[row + i][col].hasShip()) {
                System.out.println("Another ship obstructs the path.");
                return false;
            }
        }
        for(int i = 0; i < length; i++) {
            if (direction == Ship.HORIZONTAL) {
                grid[row][col + i].setShip(true);
            }
            else {
                grid[row + i][col].setShip(true);
            }
        }
        return true;

    }
    
}
