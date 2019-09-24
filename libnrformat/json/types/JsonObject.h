//
//  Json.hpp
//  libNrFormat
//
//  Created by Nyhl Rawlings on 17/09/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef JsonObject_hpp
#define JsonObject_hpp

#include <stdio.h>

#include <libnrcore/memory/Ref.h>
#include <libnrcore/memory/String.h>
#include <libnrcore/memory/Array.h>
#include <libnrcore/memory/HashMap.h>

#include "JsonValue.h"

namespace nrcore {

    class JsonObject : public JsonValue {
        
    public:
        JsonObject(String JsonObject);
        JsonObject(const JsonObject &json);
        virtual ~JsonObject();
        
        TYPE getType();
        String toString();
        
        bool parse(String json);
        
        Ref<JsonValue> getValue(String name);
        
        void addValue(String name, Ref<JsonValue> value);
        
        HashMap< Ref<JsonValue> > getValues();
        
    protected:
        TYPE type;
        HashMap< Ref<JsonValue> > values;
        String value;
    };
    
}

#endif /* JsonObject_hpp */
