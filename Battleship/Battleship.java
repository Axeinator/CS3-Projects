public class Battleship extends ConsoleProgram
{
    private static final int GRID_SIZE = 10;
    public void run()
    {
        // Start here! This class should interact with the user
        // to play the game of Battleship
        
        // You only need to allow for the user to set up each player's
        // ships and for each player to make a guess on the other player's grid
        // Don't worry about finishing the whole game yet.
        
        // You will probably need to make additions to the Player class to
        // allow for this setting up and guessing
        
        Player player1 = new Player();
        Player player2 = new Player();
        
        System.out.println("Player 1, please place your ships: ");
        setupShips(player1);
        System.out.println("Player 2, please place your ships: ");
        setupShips(player2);
        
        while (true) {
            System.out.println("Player 1, please make a guess: ");
            askForGuess(player1, player2);
            System.out.println("Player 2, please make a guess: ");
            askForGuess(player2, player1);
        }
    }
    
    private void setupShips(Player player) {
        for (Ship s : player.getShips()) {
            int r = -1;
            int c = -1;
            int d = -1;
            while (true) {
                r = (char) readLine("Row: ").charAt(0) - 65;
                c = readInt("Col: ");
                System.out.println(c);
                d = readInt("Direction (0 hor, 1 ver): ");
                s.setLocation(r, c);
                s.setDirection(d);
                if (isValidPlacement(player, r, c, d) && player.getOwnGrid().addShip(s)) break;
            }
        }
    }
    
    private void askForGuess(Player player, Player opponent) {
        int row = readInt("Row: ");
        int col = readInt("Col: ");
        if (opponent.getOwnGrid().alreadyGuessed(row, col)) {
            System.out.println("You've already guessed that location.");
            return;
        }
        if (opponent.getOwnGrid().hasShip(row, col)) {
            opponent.getOwnGrid().markHit(row, col);
            player.getOpponentGrid().markHit(row, col);
            System.out.println("Hit!");
        }
        else {
            opponent.getOwnGrid().markMiss(row, col);
            player.getOpponentGrid().markMiss(row, col);
            System.out.println("Miss!");
        }
        System.out.println("Your opponent's board: ");
        player.getOpponentGrid().printStatus();
    }
    private boolean isValidPlacement(Player player, int row, int col, int dir) {
        if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE) {
            println("Invalid row or column. Please try again.");
            return false;
        }
        
        if (dir != 0 && dir != 1) {
            println("Invalid direction. Please enter 0 for horizontal or 1 for vertical.");
            return false;
        }
        
        return true;
    }
}
