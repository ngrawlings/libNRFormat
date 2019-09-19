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
    
    Json::Json(JsonValue::TYPE type) {
        switch (type) {
            case JsonValue::OBJECT:
                value = Ref<JsonValue>(new JsonObject("{}"));
                break;
                
            case JsonValue::ARRAY:
                value = Ref<JsonValue>(new JsonArray("[]"));
                break;
                
            case JsonValue::STRING:
                value = Ref<JsonValue>(new JsonString(""));
                break;
                
            case JsonValue::VALUE:
                value = Ref<JsonValue>(new JsonNumber("0"));
                break;
                
            default:
                throw "Invalid Type";
                break;
        }
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
    
    String Json::getStringValue(String path) {
        StringList names(path, ".");
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
    
    int Json::getIntValue(String path) {
        String v = getStringValue(path);
        return atoi(v.operator char *());
    }
    
    Array< Ref<JsonValue> > Json::getArray(String path) {
        StringList names(path, ".");
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
    
    bool Json::setValue(String path, Ref<JsonValue> value) {
        StringList names(path, ".");
        ssize_t len = names.length();
        Ref<JsonValue> val = this->value;
        JsonObject *jo;
        
        for (int i=0; i<len-1; i++) {
            jo = (JsonObject*)val.getPtr();
            try {
                val = jo->getValue(names[i]);
            } catch(const char *) {
                jo->addValue(names[i], Ref<JsonValue>(new JsonObject("{}")));
                val = jo->getValue(names[i]);
            }
        }
        jo = (JsonObject*)val.getPtr();
        jo->addValue(names[(unsigned int)len-1], value);
        
        return true;
    }
    
}
