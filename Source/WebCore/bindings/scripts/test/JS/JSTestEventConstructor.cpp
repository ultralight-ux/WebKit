/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "JSTestEventConstructor.h"

#include "JSDOMBinding.h"
#include "JSDOMBindingCaller.h"
#include "JSDOMConstructor.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMWrapperCache.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

template<> TestEventConstructor::Init convertDictionary<TestEventConstructor::Init>(ExecState& state, JSValue value)
{
    VM& vm = state.vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    bool isNullOrUndefined = value.isUndefinedOrNull();
    auto* object = isNullOrUndefined ? nullptr : value.getObject();
    if (UNLIKELY(!isNullOrUndefined && !object)) {
        throwTypeError(&state, throwScope);
        return { };
    }
    if (UNLIKELY(object && object->type() == RegExpObjectType)) {
        throwTypeError(&state, throwScope);
        return { };
    }
    TestEventConstructor::Init result;
    JSValue bubblesValue = isNullOrUndefined ? jsUndefined() : object->get(&state, Identifier::fromString(&state, "bubbles"));
    if (!bubblesValue.isUndefined()) {
        result.bubbles = convert<IDLBoolean>(state, bubblesValue);
        RETURN_IF_EXCEPTION(throwScope, { });
    } else
        result.bubbles = false;
    JSValue cancelableValue = isNullOrUndefined ? jsUndefined() : object->get(&state, Identifier::fromString(&state, "cancelable"));
    if (!cancelableValue.isUndefined()) {
        result.cancelable = convert<IDLBoolean>(state, cancelableValue);
        RETURN_IF_EXCEPTION(throwScope, { });
    } else
        result.cancelable = false;
    JSValue composedValue = isNullOrUndefined ? jsUndefined() : object->get(&state, Identifier::fromString(&state, "composed"));
    if (!composedValue.isUndefined()) {
        result.composed = convert<IDLBoolean>(state, composedValue);
        RETURN_IF_EXCEPTION(throwScope, { });
    } else
        result.composed = false;
    JSValue attr2Value = isNullOrUndefined ? jsUndefined() : object->get(&state, Identifier::fromString(&state, "attr2"));
    if (!attr2Value.isUndefined()) {
        result.attr2 = convert<IDLDOMString>(state, attr2Value);
        RETURN_IF_EXCEPTION(throwScope, { });
    } else
        result.attr2 = emptyString();
    JSValue attr3Value = isNullOrUndefined ? jsUndefined() : object->get(&state, Identifier::fromString(&state, "attr3"));
    if (!attr3Value.isUndefined()) {
        result.attr3 = convert<IDLDOMString>(state, attr3Value);
        RETURN_IF_EXCEPTION(throwScope, { });
    } else
        result.attr3 = emptyString();
    return result;
}

// Attributes

JSC::EncodedJSValue jsTestEventConstructorAttr1(JSC::ExecState*, JSC::EncodedJSValue, JSC::PropertyName);
JSC::EncodedJSValue jsTestEventConstructorAttr2(JSC::ExecState*, JSC::EncodedJSValue, JSC::PropertyName);
#if ENABLE(SPECIAL_EVENT)
JSC::EncodedJSValue jsTestEventConstructorAttr3(JSC::ExecState*, JSC::EncodedJSValue, JSC::PropertyName);
#endif
JSC::EncodedJSValue jsTestEventConstructorConstructor(JSC::ExecState*, JSC::EncodedJSValue, JSC::PropertyName);
bool setJSTestEventConstructorConstructor(JSC::ExecState*, JSC::EncodedJSValue, JSC::EncodedJSValue);

class JSTestEventConstructorPrototype : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSTestEventConstructorPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSTestEventConstructorPrototype* ptr = new (NotNull, JSC::allocateCell<JSTestEventConstructorPrototype>(vm.heap)) JSTestEventConstructorPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSTestEventConstructorPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};

using JSTestEventConstructorConstructor = JSDOMConstructor<JSTestEventConstructor>;

template<> EncodedJSValue JSC_HOST_CALL JSTestEventConstructorConstructor::construct(ExecState* state)
{
    VM& vm = state->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    auto* castedThis = jsCast<JSTestEventConstructorConstructor*>(state->jsCallee());
    ASSERT(castedThis);
    if (UNLIKELY(state->argumentCount() < 1))
        return throwVMError(state, throwScope, createNotEnoughArgumentsError(state));
    auto type = convert<IDLDOMString>(*state, state->uncheckedArgument(0));
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    auto eventInitDict = convert<IDLDictionary<TestEventConstructor::Init>>(*state, state->argument(1));
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    auto object = TestEventConstructor::create(WTFMove(type), WTFMove(eventInitDict));
    return JSValue::encode(toJSNewlyCreated<IDLInterface<TestEventConstructor>>(*state, *castedThis->globalObject(), WTFMove(object)));
}

template<> JSValue JSTestEventConstructorConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    return JSEvent::getConstructor(vm, &globalObject);
}

template<> void JSTestEventConstructorConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->prototype, JSTestEventConstructor::prototype(vm, globalObject), DontDelete | ReadOnly | DontEnum);
    putDirect(vm, vm.propertyNames->name, jsNontrivialString(&vm, String(ASCIILiteral("TestEventConstructor"))), ReadOnly | DontEnum);
    putDirect(vm, vm.propertyNames->length, jsNumber(1), ReadOnly | DontEnum);
}

template<> const ClassInfo JSTestEventConstructorConstructor::s_info = { "TestEventConstructor", &Base::s_info, 0, CREATE_METHOD_TABLE(JSTestEventConstructorConstructor) };

/* Hash table for prototype */

static const HashTableValue JSTestEventConstructorPrototypeTableValues[] =
{
    { "constructor", DontEnum, NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestEventConstructorConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestEventConstructorConstructor) } },
    { "attr1", ReadOnly | CustomAccessor, NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestEventConstructorAttr1), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    { "attr2", ReadOnly | CustomAccessor, NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestEventConstructorAttr2), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
#if ENABLE(SPECIAL_EVENT)
    { "attr3", ReadOnly | CustomAccessor, NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestEventConstructorAttr3), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
#else
    { 0, 0, NoIntrinsic, { 0, 0 } },
#endif
};

const ClassInfo JSTestEventConstructorPrototype::s_info = { "TestEventConstructorPrototype", &Base::s_info, 0, CREATE_METHOD_TABLE(JSTestEventConstructorPrototype) };

void JSTestEventConstructorPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSTestEventConstructorPrototypeTableValues, *this);
}

const ClassInfo JSTestEventConstructor::s_info = { "TestEventConstructor", &Base::s_info, 0, CREATE_METHOD_TABLE(JSTestEventConstructor) };

JSTestEventConstructor::JSTestEventConstructor(Structure* structure, JSDOMGlobalObject& globalObject, Ref<TestEventConstructor>&& impl)
    : JSEvent(structure, globalObject, WTFMove(impl))
{
}

void JSTestEventConstructor::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(vm, info()));

}

JSObject* JSTestEventConstructor::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSTestEventConstructorPrototype::create(vm, &globalObject, JSTestEventConstructorPrototype::createStructure(vm, &globalObject, JSEvent::prototype(vm, globalObject)));
}

JSObject* JSTestEventConstructor::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSTestEventConstructor>(vm, globalObject);
}

template<> inline JSTestEventConstructor* BindingCaller<JSTestEventConstructor>::castForAttribute(ExecState& state, EncodedJSValue thisValue)
{
    return jsDynamicDowncast<JSTestEventConstructor*>(state.vm(), JSValue::decode(thisValue));
}

static inline JSValue jsTestEventConstructorAttr1Getter(ExecState&, JSTestEventConstructor&, ThrowScope& throwScope);

EncodedJSValue jsTestEventConstructorAttr1(ExecState* state, EncodedJSValue thisValue, PropertyName)
{
    return BindingCaller<JSTestEventConstructor>::attribute<jsTestEventConstructorAttr1Getter>(state, thisValue, "attr1");
}

static inline JSValue jsTestEventConstructorAttr1Getter(ExecState& state, JSTestEventConstructor& thisObject, ThrowScope& throwScope)
{
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(state);
    auto& impl = thisObject.wrapped();
    JSValue result = toJS<IDLDOMString>(state, impl.attr1());
    return result;
}

static inline JSValue jsTestEventConstructorAttr2Getter(ExecState&, JSTestEventConstructor&, ThrowScope& throwScope);

EncodedJSValue jsTestEventConstructorAttr2(ExecState* state, EncodedJSValue thisValue, PropertyName)
{
    return BindingCaller<JSTestEventConstructor>::attribute<jsTestEventConstructorAttr2Getter>(state, thisValue, "attr2");
}

static inline JSValue jsTestEventConstructorAttr2Getter(ExecState& state, JSTestEventConstructor& thisObject, ThrowScope& throwScope)
{
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(state);
    auto& impl = thisObject.wrapped();
    JSValue result = toJS<IDLDOMString>(state, impl.attr2());
    return result;
}

#if ENABLE(SPECIAL_EVENT)
static inline JSValue jsTestEventConstructorAttr3Getter(ExecState&, JSTestEventConstructor&, ThrowScope& throwScope);

EncodedJSValue jsTestEventConstructorAttr3(ExecState* state, EncodedJSValue thisValue, PropertyName)
{
    return BindingCaller<JSTestEventConstructor>::attribute<jsTestEventConstructorAttr3Getter>(state, thisValue, "attr3");
}

static inline JSValue jsTestEventConstructorAttr3Getter(ExecState& state, JSTestEventConstructor& thisObject, ThrowScope& throwScope)
{
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(state);
    auto& impl = thisObject.wrapped();
    JSValue result = toJS<IDLDOMString>(state, impl.attr3());
    return result;
}

#endif

EncodedJSValue jsTestEventConstructorConstructor(ExecState* state, EncodedJSValue thisValue, PropertyName)
{
    VM& vm = state->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    JSTestEventConstructorPrototype* domObject = jsDynamicDowncast<JSTestEventConstructorPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!domObject))
        return throwVMTypeError(state, throwScope);
    return JSValue::encode(JSTestEventConstructor::getConstructor(state->vm(), domObject->globalObject()));
}

bool setJSTestEventConstructorConstructor(ExecState* state, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    VM& vm = state->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    JSValue value = JSValue::decode(encodedValue);
    JSTestEventConstructorPrototype* domObject = jsDynamicDowncast<JSTestEventConstructorPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!domObject)) {
        throwVMTypeError(state, throwScope);
        return false;
    }
    // Shadowing a built-in constructor
    return domObject->putDirect(state->vm(), state->propertyNames().constructor, value);
}

JSValue JSTestEventConstructor::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestEventConstructorConstructor>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable: 4483)
extern "C" { extern void (*const __identifier("??_7TestEventConstructor@WebCore@@6B@")[])(); }
#else
extern "C" { extern void* _ZTVN7WebCore20TestEventConstructorE[]; }
#endif
#endif

JSC::JSValue toJSNewlyCreated(JSC::ExecState*, JSDOMGlobalObject* globalObject, Ref<TestEventConstructor>&& impl)
{

#if ENABLE(BINDING_INTEGRITY)
    void* actualVTablePointer = *(reinterpret_cast<void**>(impl.ptr()));
#if PLATFORM(WIN)
    void* expectedVTablePointer = reinterpret_cast<void*>(__identifier("??_7TestEventConstructor@WebCore@@6B@"));
#else
    void* expectedVTablePointer = &_ZTVN7WebCore20TestEventConstructorE[2];
#if COMPILER(CLANG)
    // If this fails TestEventConstructor does not have a vtable, so you need to add the
    // ImplementationLacksVTable attribute to the interface definition
    static_assert(__is_polymorphic(TestEventConstructor), "TestEventConstructor is not polymorphic");
#endif
#endif
    // If you hit this assertion you either have a use after free bug, or
    // TestEventConstructor has subclasses. If TestEventConstructor has subclasses that get passed
    // to toJS() we currently require TestEventConstructor you to opt out of binding hardening
    // by adding the SkipVTableValidation attribute to the interface IDL definition
    RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    return createWrapper<TestEventConstructor>(globalObject, WTFMove(impl));
}

JSC::JSValue toJS(JSC::ExecState* state, JSDOMGlobalObject* globalObject, TestEventConstructor& impl)
{
    return wrap(state, globalObject, impl);
}


}