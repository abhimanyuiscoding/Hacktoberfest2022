HillClimbing(problem){
   currentState = problem.startState
   goal = false
   while(!goal){
      neighbour = highest valued successor of currentState
      if neighbour.value <= currentState.value
         goal = true
      else
         currentState = neighbour
   }
 }
