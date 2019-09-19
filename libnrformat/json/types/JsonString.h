//
//  JsonString.hpp
//  libNrFormat
//
//  Created by Nyhl Rawlings on 19/09/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef JsonString_hpp
#define JsonString_hpp

#include <stdio.h>
#include "JsonValue.h"

namespace nrcore {
    
    class JsonString : public JsonValue {
    public:
        JsonString(String json);
        JsonString(const JsonString &json);
        virtual ~JsonString();
        
        TYPE getType();
        String toString();
        
        String getValue();
        
    protected:
        String value;
    };
    
}

#endif /* JsonString_hpp */
