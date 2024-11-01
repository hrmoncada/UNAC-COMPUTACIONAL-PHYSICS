extern "C" {
	Geek* Geek_new(){ 
        return new Geek();
        
    }
    
	void Geek_myFunction(Geek* geek){
        geek -> myFunction(); 
    }
}
