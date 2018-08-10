
// RIGHT EDGE TREE
if(gameboard[1][2] == 'O') // RE
{
    {
        gameboard[0][0] = 'X'; // TLC
    }
    if(gameboard[1][2] == 'O' && gameboard[2][2] == 'O') // RE; BRC
        {
            gameboard[0][2] = 'X'; // TRC
        }
        if(gameboard[1][2] == 'O' && gameboard[2][2] == 'O' && gameboard[2][0] == 'O') // RE; BRC; BLC
            {
                gameboard[0][1] = 'X'; // TE
            }
        else if(gameboard[1][2] == 'O' && gameboard[2][2] == 'O' && gameboard[0][1] == 'O') // RE; BRC; TE
            {
                gameboard[2][0] = 'X'; // BLC;
            }
    else
        gameboard[2][2] = 'X'; // BRC to win if they don't move BRC
}
// BOTTOM EDGE TREE
if(gameboard[2][1] == 'O') // BE
{
    {
        gameboard[0][0] = 'X'; // TLC
    }
    if(gameboard[2][1] == 'O' && gameboard[2][2] == 'O') // BE; BRC
        {
            gameboard[2][0] = 'X'; // BLC (and to block)
        }
        if(gameboard[2][1] == 'O' && gameboard[2][2] == 'O' && gameboard[0][2]) // BE; BRC; TRC
            {
                gameboard[1][0] = 'X'; // LE
            }
        else if(gameboard[2][1] == 'O' && gameboard[2][2] == 'O' && gameboard[0][2]) // BE; BRC; LE
            {
                gameboard[0][2] = 'X'; // TRC
            }
    else
        gameboard[2][2] = 'X'; // BRC to win of they don't move BRC
}
// LEFT EDGE TREE
if(gameboard[1][0] == 'O') // LE
{
    {
        gameboard[2][2] = 'X'; // BRC
    }
    if(gameboard[1][0] == 'O' && gameboard[0][0] == 'O') // LE; TLC
        {
            gameboard[2][0] = 'X'; // BLC
        }
        if(gameboard[1][0] == 'O' && gameboard[0][0] == 'O' && gameboard[0][2] == 'O') // LE; TLC; TRC
            {
                gameboard[2][1] = 'X'; // BE to win
            }
        else if(gameboard[1][0] == 'O' && gameboard[0][0] == 'O' && gameboard[2][1] == 'O') // LE; TLC; BE
            {
                gameboard[2][0] = 'X'; // BLC to win
            }
    else
        gameboard[2][0] = 'X'; // BLC to win if they don't move BLC
}
// TOP EDGE TREE
if(gameboard[0][1] == 'O') // TE
{
    {
        gameboard[2][2] = 'X'; // BRC
    }
    if(gameboard[0][1] == 'O' && gameboard[0][0] == 'O') // TE; TLC
        {
            gameboard[0][2] = 'X'; // TRC
        }
        if(gameboard[0][1] == 'O' && gameboard[0][0] == 'O' && gameboard[2][0] == 'O') // LE; TLC; BLC
            {
                gameboard[1][2] = 'X'; // RE to win
            }
        else if(gameboard[0][1] == 'O' && gameboard[0][0] == 'O' && gameboard[1][2] == 'O') // LE; TLC; RE
            {
                gameboard[2][0] = 'X'; // BLC to win
            }
    else
        gameboard[2][0] = 'X'; // BLC to win if they don't move BLC
}