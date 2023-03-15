Prepare commit message hook Benefits:    
    * You don't have to include ticket id manually in commit message. Ticket ID is automatically prepended to commit message.

Practices kept:   
    * Automatically convert first element of the commit message to uppercase.
    * Cannot insert more than 50 characters to subject line    
    * Cannot insert duplicate ticket IDs (Cannot insert ticket ID manually)    
    * Cannot end the commit message with a period (If entered, it is automatically removed) 
    
How to install:    
    * In your local repository go to following location    
    * .git -> hooks    
    * Replace 'prepare-commit-msg-sample' with following file