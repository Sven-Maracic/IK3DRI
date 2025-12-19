// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyProjectPlayerController.h"

#ifdef MYPROJECT_MyProjectPlayerController_generated_h
#error "MyProjectPlayerController.generated.h already included, missing '#pragma once' in MyProjectPlayerController.h"
#endif
#define MYPROJECT_MyProjectPlayerController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AMyProjectPlayerController ***********************************************
MYPROJECT_API UClass* Z_Construct_UClass_AMyProjectPlayerController_NoRegister();

#define FID_Users_adria_Documents_Fax_Unreal_Grupni_IK3DRI_MyProject_Source_MyProject_MyProjectPlayerController_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyProjectPlayerController(); \
	friend struct Z_Construct_UClass_AMyProjectPlayerController_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend MYPROJECT_API UClass* Z_Construct_UClass_AMyProjectPlayerController_NoRegister(); \
public: \
	DECLARE_CLASS2(AMyProjectPlayerController, APlayerController, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/MyProject"), Z_Construct_UClass_AMyProjectPlayerController_NoRegister) \
	DECLARE_SERIALIZER(AMyProjectPlayerController)


#define FID_Users_adria_Documents_Fax_Unreal_Grupni_IK3DRI_MyProject_Source_MyProject_MyProjectPlayerController_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyProjectPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	AMyProjectPlayerController(AMyProjectPlayerController&&) = delete; \
	AMyProjectPlayerController(const AMyProjectPlayerController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyProjectPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyProjectPlayerController); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyProjectPlayerController) \
	NO_API virtual ~AMyProjectPlayerController();


#define FID_Users_adria_Documents_Fax_Unreal_Grupni_IK3DRI_MyProject_Source_MyProject_MyProjectPlayerController_h_16_PROLOG
#define FID_Users_adria_Documents_Fax_Unreal_Grupni_IK3DRI_MyProject_Source_MyProject_MyProjectPlayerController_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_adria_Documents_Fax_Unreal_Grupni_IK3DRI_MyProject_Source_MyProject_MyProjectPlayerController_h_19_INCLASS_NO_PURE_DECLS \
	FID_Users_adria_Documents_Fax_Unreal_Grupni_IK3DRI_MyProject_Source_MyProject_MyProjectPlayerController_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AMyProjectPlayerController;

// ********** End Class AMyProjectPlayerController *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_adria_Documents_Fax_Unreal_Grupni_IK3DRI_MyProject_Source_MyProject_MyProjectPlayerController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
