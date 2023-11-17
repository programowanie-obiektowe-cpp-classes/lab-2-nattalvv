#pragma once
#include "Resource.hpp"

class ResourceManager
{
    public: 
        ResourceManager() 
        {
        	ob = new Resource();
		}
        
        double get()  
        {
        	return ob ->get();
		}
        
        ResourceManager(const ResourceManager& i)  
        {
        	ob = new Resource();
        	*ob = *(i.ob);	
		}
        
    	ResourceManager& operator=(const ResourceManager& i)  
    	{
    		*ob = *i.ob;
    		return *this;  
		}
		
		ResourceManager(ResourceManager&& i)  
		{
			ob = (i.ob);
			i.ob = nullptr;  
		}
		
		ResourceManager& operator=(ResourceManager&& i) 
    	{
    		delete ob;
    		ob = i.ob;
    		i.ob = nullptr;
    		return *this;
		}
		
		~ResourceManager()
		{
			delete ob;
		}
		
    private: 
        Resource* ob; 
};