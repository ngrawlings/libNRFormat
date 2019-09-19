//
//  JsonInvalid.hpp
//  libNrFormat
//
//  Created by Nyhl Rawlings on 19/09/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef JsonInvalid_hpp
#define JsonInvalid_hpp

#include <stdio.h>
#include "JsonValue.h"

namespace nrcore {
    
    class JsonInvalid : public JsonValue {
    public:
        JsonInvalid(String json);
        JsonInvalid(const JsonInvalid &json);
        virtual ~JsonInvalid();
        
        TYPE getType();
        String toString();
        
    protected:
        String json;
    };
    
}

#endif /* JsonInvalid_hpp */
