/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * The contents of this file are subject to the Netscape Public License
 * Version 1.0 (the "NPL"); you may not use this file except in
 * compliance with the NPL.  You may obtain a copy of the NPL at
 * http://www.mozilla.org/NPL/
 *
 * Software distributed under the NPL is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the NPL
 * for the specific language governing rights and limitations under the
 * NPL.
 *
 * The Initial Developer of this code under the NPL is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1998 Netscape Communications Corporation.  All Rights
 * Reserved.
 */
/* AUTO-GENERATED. DO NOT EDIT!!! */

#include "jsapi.h"
#include "nscore.h"
#include "nsIScriptContext.h"
#include "nsIJSScriptObject.h"
#include "nsIScriptObjectOwner.h"
#include "nsIScriptGlobalObject.h"
#include "nsIPtr.h"
#include "nsString.h"
#include "nsIDOMText.h"


static NS_DEFINE_IID(kIScriptObjectOwnerIID, NS_ISCRIPTOBJECTOWNER_IID);
static NS_DEFINE_IID(kIJSScriptObjectIID, NS_IJSSCRIPTOBJECT_IID);
static NS_DEFINE_IID(kIScriptGlobalObjectIID, NS_ISCRIPTGLOBALOBJECT_IID);
static NS_DEFINE_IID(kITextIID, NS_IDOMTEXT_IID);

NS_DEF_PTR(nsIDOMText);


/***********************************************************************/
//
// Text Properties Getter
//
PR_STATIC_CALLBACK(JSBool)
GetTextProperty(JSContext *cx, JSObject *obj, jsval id, jsval *vp)
{
  nsIDOMText *a = (nsIDOMText*)JS_GetPrivate(cx, obj);

  // If there's no private data, this must be the prototype, so ignore
  if (nsnull == a) {
    return JS_TRUE;
  }

  if (JSVAL_IS_INT(id)) {
    switch(JSVAL_TO_INT(id)) {
      case 0:
      default:
      {
        nsIJSScriptObject *object;
        if (NS_OK == a->QueryInterface(kIJSScriptObjectIID, (void**)&object)) {
          PRBool rval;
          rval =  object->GetProperty(cx, id, vp);
          NS_RELEASE(object);
          return rval;
        }
      }
    }
  }

  return PR_TRUE;
}

/***********************************************************************/
//
// Text Properties Setter
//
PR_STATIC_CALLBACK(JSBool)
SetTextProperty(JSContext *cx, JSObject *obj, jsval id, jsval *vp)
{
  nsIDOMText *a = (nsIDOMText*)JS_GetPrivate(cx, obj);

  // If there's no private data, this must be the prototype, so ignore
  if (nsnull == a) {
    return JS_TRUE;
  }

  if (JSVAL_IS_INT(id)) {
    switch(JSVAL_TO_INT(id)) {
      case 0:
      default:
      {
        nsIJSScriptObject *object;
        if (NS_OK == a->QueryInterface(kIJSScriptObjectIID, (void**)&object)) {
          PRBool rval;
          rval =  object->SetProperty(cx, id, vp);
          NS_RELEASE(object);
          return rval;
        }
      }
    }
  }

  return PR_TRUE;
}


//
// Text finalizer
//
PR_STATIC_CALLBACK(void)
FinalizeText(JSContext *cx, JSObject *obj)
{
  nsIDOMText *a = (nsIDOMText*)JS_GetPrivate(cx, obj);
  
  if (nsnull != a) {
    // get the js object
    nsIScriptObjectOwner *owner = nsnull;
    if (NS_OK == a->QueryInterface(kIScriptObjectOwnerIID, (void**)&owner)) {
      owner->ResetScriptObject();
      NS_RELEASE(owner);
    }

    NS_RELEASE(a);
  }
}


//
// Text enumerate
//
PR_STATIC_CALLBACK(JSBool)
EnumerateText(JSContext *cx, JSObject *obj)
{
  nsIDOMText *a = (nsIDOMText*)JS_GetPrivate(cx, obj);
  
  if (nsnull != a) {
    // get the js object
    nsIJSScriptObject *object;
    if (NS_OK == a->QueryInterface(kIJSScriptObjectIID, (void**)&object)) {
      object->EnumerateProperty(cx);
      NS_RELEASE(object);
    }
  }
  return JS_TRUE;
}


//
// Text resolve
//
PR_STATIC_CALLBACK(JSBool)
ResolveText(JSContext *cx, JSObject *obj, jsval id)
{
  nsIDOMText *a = (nsIDOMText*)JS_GetPrivate(cx, obj);
  
  if (nsnull != a) {
    // get the js object
    nsIJSScriptObject *object;
    if (NS_OK == a->QueryInterface(kIJSScriptObjectIID, (void**)&object)) {
      object->Resolve(cx, id);
      NS_RELEASE(object);
    }
  }
  return JS_TRUE;
}


//
// Native method SplitText
//
PR_STATIC_CALLBACK(JSBool)
TextSplitText(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
  nsIDOMText *nativeThis = (nsIDOMText*)JS_GetPrivate(cx, obj);
  JSBool rBool = JS_FALSE;
  nsIDOMText* nativeRet;
  PRUint32 b0;

  *rval = JSVAL_NULL;

  // If there's no private data, this must be the prototype, so ignore
  if (nsnull == nativeThis) {
    return JS_TRUE;
  }

  if (argc >= 1) {

    if (!JS_ValueToInt32(cx, argv[0], (int32 *)&b0)) {
      JS_ReportError(cx, "Parameter must be a number");
      return JS_FALSE;
    }

    if (NS_OK != nativeThis->SplitText(b0, &nativeRet)) {
      return JS_FALSE;
    }

    if (nativeRet != nsnull) {
      nsIScriptObjectOwner *owner = nsnull;
      if (NS_OK == nativeRet->QueryInterface(kIScriptObjectOwnerIID, (void**)&owner)) {
        JSObject *object = nsnull;
        nsIScriptContext *script_cx = (nsIScriptContext *)JS_GetContextPrivate(cx);
        if (NS_OK == owner->GetScriptObject(script_cx, (void**)&object)) {
          // set the return value
          *rval = OBJECT_TO_JSVAL(object);
        }
        NS_RELEASE(owner);
      }
      NS_RELEASE(nativeRet);
    }
    else {
      *rval = JSVAL_NULL;
    }
  }
  else {
    JS_ReportError(cx, "Function splitText requires 1 parameters");
    return JS_FALSE;
  }

  return JS_TRUE;
}


//
// Native method JoinText
//
PR_STATIC_CALLBACK(JSBool)
TextJoinText(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
  nsIDOMText *nativeThis = (nsIDOMText*)JS_GetPrivate(cx, obj);
  JSBool rBool = JS_FALSE;
  nsIDOMText* nativeRet;
  nsIDOMTextPtr b0;
  nsIDOMTextPtr b1;

  *rval = JSVAL_NULL;

  // If there's no private data, this must be the prototype, so ignore
  if (nsnull == nativeThis) {
    return JS_TRUE;
  }

  if (argc >= 2) {

    if (JSVAL_IS_NULL(argv[0])){
      b0 = nsnull;
    }
    else if (JSVAL_IS_OBJECT(argv[0])) {
      nsISupports *supports0 = (nsISupports *)JS_GetPrivate(cx, JSVAL_TO_OBJECT(argv[0]));
      NS_ASSERTION(nsnull != supports0, "null pointer");

      if ((nsnull == supports0) ||
          (NS_OK != supports0->QueryInterface(kITextIID, (void **)(b0.Query())))) {
        JS_ReportError(cx, "Parameter must be of type Text");
        return JS_FALSE;
      }
    }
    else {
      JS_ReportError(cx, "Parameter must be an object");
      return JS_FALSE;
    }

    if (JSVAL_IS_NULL(argv[1])){
      b1 = nsnull;
    }
    else if (JSVAL_IS_OBJECT(argv[1])) {
      nsISupports *supports1 = (nsISupports *)JS_GetPrivate(cx, JSVAL_TO_OBJECT(argv[1]));
      NS_ASSERTION(nsnull != supports1, "null pointer");

      if ((nsnull == supports1) ||
          (NS_OK != supports1->QueryInterface(kITextIID, (void **)(b1.Query())))) {
        JS_ReportError(cx, "Parameter must be of type Text");
        return JS_FALSE;
      }
    }
    else {
      JS_ReportError(cx, "Parameter must be an object");
      return JS_FALSE;
    }

    if (NS_OK != nativeThis->JoinText(b0, b1, &nativeRet)) {
      return JS_FALSE;
    }

    if (nativeRet != nsnull) {
      nsIScriptObjectOwner *owner = nsnull;
      if (NS_OK == nativeRet->QueryInterface(kIScriptObjectOwnerIID, (void**)&owner)) {
        JSObject *object = nsnull;
        nsIScriptContext *script_cx = (nsIScriptContext *)JS_GetContextPrivate(cx);
        if (NS_OK == owner->GetScriptObject(script_cx, (void**)&object)) {
          // set the return value
          *rval = OBJECT_TO_JSVAL(object);
        }
        NS_RELEASE(owner);
      }
      NS_RELEASE(nativeRet);
    }
    else {
      *rval = JSVAL_NULL;
    }
  }
  else {
    JS_ReportError(cx, "Function joinText requires 2 parameters");
    return JS_FALSE;
  }

  return JS_TRUE;
}


/***********************************************************************/
//
// class for Text
//
JSClass TextClass = {
  "Text", 
  JSCLASS_HAS_PRIVATE,
  JS_PropertyStub,
  JS_PropertyStub,
  GetTextProperty,
  SetTextProperty,
  EnumerateText,
  ResolveText,
  JS_ConvertStub,
  FinalizeText
};


//
// Text class properties
//
static JSPropertySpec TextProperties[] =
{
  {0}
};


//
// Text class methods
//
static JSFunctionSpec TextMethods[] = 
{
  {"splitText",          TextSplitText,     1},
  {"joinText",          TextJoinText,     2},
  {0}
};


//
// Text constructor
//
PR_STATIC_CALLBACK(JSBool)
Text(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
  return JS_TRUE;
}


//
// Text class initialization
//
nsresult NS_InitTextClass(nsIScriptContext *aContext, void **aPrototype)
{
  JSContext *jscontext = (JSContext *)aContext->GetNativeContext();
  JSObject *proto = nsnull;
  JSObject *constructor = nsnull;
  JSObject *parent_proto = nsnull;
  JSObject *global = JS_GetGlobalObject(jscontext);
  jsval vp;

  if ((PR_TRUE != JS_LookupProperty(jscontext, global, "Text", &vp)) ||
      !JSVAL_IS_OBJECT(vp) ||
      ((constructor = JSVAL_TO_OBJECT(vp)) == nsnull) ||
      (PR_TRUE != JS_LookupProperty(jscontext, JSVAL_TO_OBJECT(vp), "prototype", &vp)) || 
      !JSVAL_IS_OBJECT(vp)) {

    if (NS_OK != NS_InitDataClass(aContext, (void **)&parent_proto)) {
      return NS_ERROR_FAILURE;
    }
    proto = JS_InitClass(jscontext,     // context
                         global,        // global object
                         parent_proto,  // parent proto 
                         &TextClass,      // JSClass
                         Text,            // JSNative ctor
                         0,             // ctor args
                         TextProperties,  // proto props
                         TextMethods,     // proto funcs
                         nsnull,        // ctor props (static)
                         nsnull);       // ctor funcs (static)
    if (nsnull == proto) {
      return NS_ERROR_FAILURE;
    }

  }
  else if ((nsnull != constructor) && JSVAL_IS_OBJECT(vp)) {
    proto = JSVAL_TO_OBJECT(vp);
  }
  else {
    return NS_ERROR_FAILURE;
  }

  if (aPrototype) {
    *aPrototype = proto;
  }
  return NS_OK;
}


//
// Method for creating a new Text JavaScript object
//
extern "C" NS_DOM nsresult NS_NewScriptText(nsIScriptContext *aContext, nsIDOMText *aSupports, nsISupports *aParent, void **aReturn)
{
  NS_PRECONDITION(nsnull != aContext && nsnull != aSupports && nsnull != aReturn, "null argument to NS_NewScriptText");
  JSObject *proto;
  JSObject *parent;
  nsIScriptObjectOwner *owner;
  JSContext *jscontext = (JSContext *)aContext->GetNativeContext();

  if (nsnull == aParent) {
    parent = nsnull;
  }
  else if (NS_OK == aParent->QueryInterface(kIScriptObjectOwnerIID, (void**)&owner)) {
    if (NS_OK != owner->GetScriptObject(aContext, (void **)&parent)) {
      NS_RELEASE(owner);
      return NS_ERROR_FAILURE;
    }
    NS_RELEASE(owner);
  }
  else {
    return NS_ERROR_FAILURE;
  }

  if (NS_OK != NS_InitTextClass(aContext, (void **)&proto)) {
    return NS_ERROR_FAILURE;
  }

  // create a js object for this class
  *aReturn = JS_NewObject(jscontext, &TextClass, proto, parent);
  if (nsnull != *aReturn) {
    // connect the native object to the js object
    JS_SetPrivate(jscontext, (JSObject *)*aReturn, aSupports);
    NS_ADDREF(aSupports);
  }
  else {
    return NS_ERROR_FAILURE; 
  }

  return NS_OK;
}
