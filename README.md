1.) When a fork operation is started both the parent and child process share the memory however; the stack and the heap do not share the memory. 
The stack and heap that the child process has is a copy of the parent but any modifications done to the child process will not
affect the parent's heap or stack.  Meanwhile, the Parent and child have a shared memory segment that allows them to communicate with each other.

2.) One issue faced by both operating systems is going to be problems with race conditions.  
If multiple programs are fighting for resources unanimously that can cause unforeseen complications.  
Another issue faced by operating systems is deadlocks.  When processes are queued until other processes 
are finished this can cause delays between processes successfully executing.  Lastly a major issue faced is going to be resource contention. 
If multiple processes require the same resources simultaneously this can cause strain on the system, especially if the resources it has is not 
adequate for the requirements.  Android utilitizes threads to alleviate the issues presented previously.  
Threads allow the android OS to divide the work into smaller processes that work seemingly simultaneously.  
When it comes to IOS it uses GCD or Grand Central Dispatch.  This process determines how to manage tasks, this can be done using queues.
It also will determine if the processes should be done concurrently or parallel.
