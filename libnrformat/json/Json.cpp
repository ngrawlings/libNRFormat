//
//  Json.cpp
//  libNrFormat
//
//  Created by Nyhl Rawlings on 19/09/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "Json.h"
#include "libnrcore/memory/StringList.h"

#include <stdio.h>
#include <stdlib.h>

namespace nrcore {
    
    Json::Json(String json) {
        value = JsonValue::getJsonValue(json);
    }
    
    Json::Json(const Json &json) {
        this->value = json.value;
    }
    
    Json::~Json() {
        
    }
    
    JsonValue::TYPE Json::getType() {
        return value.getPtr()->getType();
    }
    
    Ref<JsonValue> Json::getValue() {
        return value;
    }
    
    String Json::getStringValue(String name) {
        StringList names(name, ".");
        try {
            Ref<JsonValue> val = value;
            ssize_t len = names.length();
            
            if (len) {
                for (int i=0; i<len; i++) {
                    JsonObject *jo = (JsonObject*)val.getPtr();
                    val = jo->getValue(names[i]);
                }
            }
            
            switch (val.getPtr()->getType()) {
                case JsonValue::ARRAY:
                case JsonValue::OBJECT:
                case JsonValue::VALUE:
                case JsonValue::INVALID:
                    return val.getPtr()->toString();
                    
                case JsonValue::STRING:
                    return ((JsonString*)val.getPtr())->getValue();
            }
            
        } catch (const char *) {
            
        }
        return "";
    }
    
    int Json::getIntValue(String name) {
        String v = getStringValue(name);
        return atoi(v.operator char *());
    }
    
    Array< Ref<JsonValue> > Json::getArray(String name) {
        StringList names(name, ".");
        try {
            Ref<JsonValue> val = value;
            ssize_t len = names.length();
            
            if (len) {
                for (int i=0; i<len; i++) {
                    JsonObject *jo = (JsonObject*)val.getPtr();
                    val = jo->getValue(names[i]);
                }
            }
            
            if (val.getPtr()->getType() == JsonValue::ARRAY)
                return ((JsonArray*)val.getPtr())->getArray();
            
        } catch (const char *) {
            
        }
        return Array< Ref<JsonValue> >();
    }
    
}
