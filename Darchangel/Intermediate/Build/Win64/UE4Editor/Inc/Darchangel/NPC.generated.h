// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DARCHANGEL_NPC_generated_h
#error "NPC.generated.h already included, missing '#pragma once' in NPC.h"
#endif
#define DARCHANGEL_NPC_generated_h

#define Darchangel_Source_Darchangel_NPC_h_12_SPARSE_DATA
#define Darchangel_Source_Darchangel_NPC_h_12_RPC_WRAPPERS
#define Darchangel_Source_Darchangel_NPC_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define Darchangel_Source_Darchangel_NPC_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesANPC(); \
	friend struct Z_Construct_UClass_ANPC_Statics; \
public: \
	DECLARE_CLASS(ANPC, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Darchangel"), NO_API) \
	DECLARE_SERIALIZER(ANPC)


#define Darchangel_Source_Darchangel_NPC_h_12_INCLASS \
private: \
	static void StaticRegisterNativesANPC(); \
	friend struct Z_Construct_UClass_ANPC_Statics; \
public: \
	DECLARE_CLASS(ANPC, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Darchangel"), NO_API) \
	DECLARE_SERIALIZER(ANPC)


#define Darchangel_Source_Darchangel_NPC_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ANPC(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ANPC) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANPC); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANPC); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANPC(ANPC&&); \
	NO_API ANPC(const ANPC&); \
public:


#define Darchangel_Source_Darchangel_NPC_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANPC(ANPC&&); \
	NO_API ANPC(const ANPC&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANPC); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANPC); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ANPC)


#define Darchangel_Source_Darchangel_NPC_h_12_PRIVATE_PROPERTY_OFFSET
#define Darchangel_Source_Darchangel_NPC_h_9_PROLOG
#define Darchangel_Source_Darchangel_NPC_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Darchangel_Source_Darchangel_NPC_h_12_PRIVATE_PROPERTY_OFFSET \
	Darchangel_Source_Darchangel_NPC_h_12_SPARSE_DATA \
	Darchangel_Source_Darchangel_NPC_h_12_RPC_WRAPPERS \
	Darchangel_Source_Darchangel_NPC_h_12_INCLASS \
	Darchangel_Source_Darchangel_NPC_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Darchangel_Source_Darchangel_NPC_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Darchangel_Source_Darchangel_NPC_h_12_PRIVATE_PROPERTY_OFFSET \
	Darchangel_Source_Darchangel_NPC_h_12_SPARSE_DATA \
	Darchangel_Source_Darchangel_NPC_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	Darchangel_Source_Darchangel_NPC_h_12_INCLASS_NO_PURE_DECLS \
	Darchangel_Source_Darchangel_NPC_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DARCHANGEL_API UClass* StaticClass<class ANPC>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Darchangel_Source_Darchangel_NPC_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
