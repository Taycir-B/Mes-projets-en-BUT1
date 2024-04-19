		LOADSI #0
		loadaadrsi 
		loaddiadrsi 

debut	CMPSIA 
		JMPPZ Palin	
	

check 	incsi 
		loadaadrsi 
		loadbadrdi 
		cmpba 
		JMPNZ NoPalin	
		decdi
		LOADADI 	
		jmp debut 

Palin 	loada #1
		jmp fin

NoPalin loada #-1

fin		jmp fin 	






