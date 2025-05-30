cmake_minimum_required(VERSION 2.8)

project(cfe)

# Build the stdlib plugin.
add_subdirectory(stdlib-support)

# C++ standard.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler flags.
set(CFE_CXX_FLAGS)
set(CFE_CXX_FLAGS "${CFE_CXX_FLAGS} -g")
set(CFE_CXX_FLAGS "${CFE_CXX_FLAGS} -Wall \
                                    -Wsign-compare")

set(CFE_CXX_FLAGS "${CFE_CXX_FLAGS} -DEXPORT_C_API")
set(PLUGIN_CXX_FLAGS "${CFE_CXX_FLAGS} -DEXPORT_PLUGIN_API")

set(CMAKE_MACOSX_RPATH TRUE)

set(PLUGIN_SOURCES
    # Plugin API files
    ${PROJECT_SOURCE_DIR}/plugin-api/PluginConfig.h
    ${PROJECT_SOURCE_DIR}/plugin-api/DeclarationInterceptor.h
    ${PROJECT_SOURCE_DIR}/plugin-api/SourceInspector.h
)

set(CFE_SOURCES
    # Main
    ${PROJECT_SOURCE_DIR}/API.h
    ${PROJECT_SOURCE_DIR}/Fwds.h

    # Infra
    ${PROJECT_SOURCE_DIR}/infra/List.h
    ${PROJECT_SOURCE_DIR}/infra/Managed.h
    ${PROJECT_SOURCE_DIR}/infra/Managed.cpp
    ${PROJECT_SOURCE_DIR}/infra/MemoryPool.h
    ${PROJECT_SOURCE_DIR}/infra/MemoryPool.cpp

    # Syntax
    ${PROJECT_SOURCE_DIR}/syntax/Lexeme.h
    ${PROJECT_SOURCE_DIR}/syntax/Lexeme.cpp
    ${PROJECT_SOURCE_DIR}/syntax/Lexeme_Identifier.h
    ${PROJECT_SOURCE_DIR}/syntax/Lexeme_Identifier.cpp
    ${PROJECT_SOURCE_DIR}/syntax/Lexeme_Constant.h
    ${PROJECT_SOURCE_DIR}/syntax/Lexeme_Constant.cpp
    ${PROJECT_SOURCE_DIR}/syntax/Lexeme_StringLiteral.h
    ${PROJECT_SOURCE_DIR}/syntax/Lexeme_StringLiteral.cpp
    ${PROJECT_SOURCE_DIR}/syntax/Lexeme_ALL.h
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxDumper.h
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxFacts.h
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxHolder.h
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxHolder.cpp
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxKind.h
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxNamePrinter.h
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxNamePrinter.cpp
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxNode.cpp
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxNode.h
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxNodeList.h
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxNodeList.cpp
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxNodes.h
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxNodes_Common.h
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxNodes_Declarations.h
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxNodes_Expressions.h
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxNodes_Statements.h
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxNodes_MIXIN.h
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxReference.cpp
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxReference.h
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxTree.h
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxTree.cpp
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxToken.cpp
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxToken.h
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxUtilities.cpp
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxUtilities.h
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxVisitor.cpp
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxVisitor.h
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxVisitor__MACROS__.inc
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxWriterDOTFormat.h
    ${PROJECT_SOURCE_DIR}/syntax/SyntaxWriterDOTFormat.cpp

    # Parser
    ${PROJECT_SOURCE_DIR}/parser/DiagnosticsReporter_Lexer.cpp
    ${PROJECT_SOURCE_DIR}/parser/DiagnosticsReporter_Parser.cpp
    ${PROJECT_SOURCE_DIR}/parser/Keywords.cpp
    ${PROJECT_SOURCE_DIR}/parser/LanguageDialect.h
    ${PROJECT_SOURCE_DIR}/parser/LanguageDialect.cpp
    ${PROJECT_SOURCE_DIR}/parser/LanguageExtensions.h
    ${PROJECT_SOURCE_DIR}/parser/LanguageExtensions.cpp
    ${PROJECT_SOURCE_DIR}/parser/LexedTokens.h
    ${PROJECT_SOURCE_DIR}/parser/LexedTokens.cpp
    ${PROJECT_SOURCE_DIR}/parser/Lexer.h
    ${PROJECT_SOURCE_DIR}/parser/Lexer.cpp
    ${PROJECT_SOURCE_DIR}/parser/LineDirective.h
    ${PROJECT_SOURCE_DIR}/parser/LineDirective.cpp
    ${PROJECT_SOURCE_DIR}/parser/MacroTranslations.h
    ${PROJECT_SOURCE_DIR}/parser/MacroTranslations.cpp
    ${PROJECT_SOURCE_DIR}/parser/Parser.h
    ${PROJECT_SOURCE_DIR}/parser/Parser__IMPL__.inc
    ${PROJECT_SOURCE_DIR}/parser/Parser.cpp
    ${PROJECT_SOURCE_DIR}/parser/Parser_Common.cpp
    ${PROJECT_SOURCE_DIR}/parser/Parser_Declarations.cpp
    ${PROJECT_SOURCE_DIR}/parser/Parser_Expressions.cpp
    ${PROJECT_SOURCE_DIR}/parser/Parser_Statements.cpp
    ${PROJECT_SOURCE_DIR}/parser/ParseOptions.h
    ${PROJECT_SOURCE_DIR}/parser/ParseOptions.cpp
    ${PROJECT_SOURCE_DIR}/parser/TextCompleteness.h
    ${PROJECT_SOURCE_DIR}/parser/TextPreprocessingState.h
    ${PROJECT_SOURCE_DIR}/parser/Unparser.h
    ${PROJECT_SOURCE_DIR}/parser/Unparser.cpp

    # Reparser
    ${PROJECT_SOURCE_DIR}/reparser/Disambiguator.h
    ${PROJECT_SOURCE_DIR}/reparser/Disambiguator.cpp
    ${PROJECT_SOURCE_DIR}/reparser/Disambiguator_GuidelineImposition.h
    ${PROJECT_SOURCE_DIR}/reparser/Disambiguator_GuidelineImposition.cpp
    ${PROJECT_SOURCE_DIR}/reparser/Disambiguator_SyntaxCorrelation.h
    ${PROJECT_SOURCE_DIR}/reparser/Disambiguator_SyntaxCorrelation.cpp
    ${PROJECT_SOURCE_DIR}/reparser/Disambiguator_TypeSynonymsVerification.h
    ${PROJECT_SOURCE_DIR}/reparser/Disambiguator_TypeSynonymsVerification.cpp
    ${PROJECT_SOURCE_DIR}/reparser/NameCatalog.h
    ${PROJECT_SOURCE_DIR}/reparser/NameCatalog.cpp
    ${PROJECT_SOURCE_DIR}/reparser/NameCataloger.h
    ${PROJECT_SOURCE_DIR}/reparser/NameCataloger.cpp
    ${PROJECT_SOURCE_DIR}/reparser/Reparser.h
    ${PROJECT_SOURCE_DIR}/reparser/Reparser.cpp

    # Symbols
    ${PROJECT_SOURCE_DIR}/symbols/MIXIN_NameableDeclarationSymbol.h
    ${PROJECT_SOURCE_DIR}/symbols/MIXIN_NameableDeclarationSymbol.cpp
    ${PROJECT_SOURCE_DIR}/symbols/MIXIN_TypeableDeclarationSymbol.h
    ${PROJECT_SOURCE_DIR}/symbols/MIXIN_TypeableDeclarationSymbol.cpp
    ${PROJECT_SOURCE_DIR}/symbols/SymbolCategory.h
    ${PROJECT_SOURCE_DIR}/symbols/SymbolKind.h
    ${PROJECT_SOURCE_DIR}/symbols/Symbol__IMPL__.inc
    ${PROJECT_SOURCE_DIR}/symbols/Symbol_ALL.h
    ${PROJECT_SOURCE_DIR}/symbols/Symbol.cpp
    ${PROJECT_SOURCE_DIR}/symbols/Symbol.h
    ${PROJECT_SOURCE_DIR}/symbols/Symbol_Program.cpp
    ${PROJECT_SOURCE_DIR}/symbols/Symbol_Program.h
    ${PROJECT_SOURCE_DIR}/symbols/Symbol_TranslationUnit.cpp
    ${PROJECT_SOURCE_DIR}/symbols/Symbol_TranslationUnit.h
    ${PROJECT_SOURCE_DIR}/symbols/Symbol_Declaration.cpp
    ${PROJECT_SOURCE_DIR}/symbols/Symbol_Declaration.h
    ${PROJECT_SOURCE_DIR}/symbols/DeclarationCategory.h
    ${PROJECT_SOURCE_DIR}/symbols/Declaration__IMPL__.inc
    ${PROJECT_SOURCE_DIR}/symbols/Declaration_Function.cpp
    ${PROJECT_SOURCE_DIR}/symbols/Declaration_Function.h
    ${PROJECT_SOURCE_DIR}/symbols/Declaration_Member.cpp
    ${PROJECT_SOURCE_DIR}/symbols/Declaration_Member.h
    ${PROJECT_SOURCE_DIR}/symbols/Declaration_Object.cpp
    ${PROJECT_SOURCE_DIR}/symbols/Declaration_Object.h
    ${PROJECT_SOURCE_DIR}/symbols/Declaration_Type.cpp
    ${PROJECT_SOURCE_DIR}/symbols/Declaration_Type.h
    ${PROJECT_SOURCE_DIR}/symbols/ObjectDeclaration_Parameter.cpp
    ${PROJECT_SOURCE_DIR}/symbols/ObjectDeclaration_Parameter.h
    ${PROJECT_SOURCE_DIR}/symbols/ObjectDeclaration_Variable.cpp
    ${PROJECT_SOURCE_DIR}/symbols/ObjectDeclaration_Variable.h
    ${PROJECT_SOURCE_DIR}/symbols/MemberDeclaration_Enumerator.cpp
    ${PROJECT_SOURCE_DIR}/symbols/MemberDeclaration_Enumerator.h
    ${PROJECT_SOURCE_DIR}/symbols/MemberDeclaration_Field.cpp
    ${PROJECT_SOURCE_DIR}/symbols/MemberDeclaration_Field.h
    ${PROJECT_SOURCE_DIR}/symbols/TypeDeclarationCategory.h
    ${PROJECT_SOURCE_DIR}/symbols/TypeDeclaration__IMPL__.inc
    ${PROJECT_SOURCE_DIR}/symbols/TypeDeclaration_Tag.h
    ${PROJECT_SOURCE_DIR}/symbols/TypeDeclaration_Tag.cpp
    ${PROJECT_SOURCE_DIR}/symbols/TypeDeclaration_Typedef.cpp
    ${PROJECT_SOURCE_DIR}/symbols/TypeDeclaration_Typedef.h
    ${PROJECT_SOURCE_DIR}/symbols/TagDeclarationCategory.h
    ${PROJECT_SOURCE_DIR}/symbols/TagDeclaration_Enum.cpp
    ${PROJECT_SOURCE_DIR}/symbols/TagDeclaration_Enum.h
    ${PROJECT_SOURCE_DIR}/symbols/TagDeclaration_StructOrUnion.cpp
    ${PROJECT_SOURCE_DIR}/symbols/TagDeclaration_StructOrUnion.h
    ${PROJECT_SOURCE_DIR}/symbols/StructOrUnionDeclaration_Struct.cpp
    ${PROJECT_SOURCE_DIR}/symbols/StructOrUnionDeclaration_Struct.h
    ${PROJECT_SOURCE_DIR}/symbols/StructOrUnionDeclaration_Union.cpp
    ${PROJECT_SOURCE_DIR}/symbols/StructOrUnionDeclaration_Union.h

    # Semantics
    ${PROJECT_SOURCE_DIR}/sema/DeclarationBinder__MACROS__.inc
    ${PROJECT_SOURCE_DIR}/sema/DeclarationBinder.h
    ${PROJECT_SOURCE_DIR}/sema/DeclarationBinder.cpp
    ${PROJECT_SOURCE_DIR}/sema/DeclarationBinder_Declarators.cpp
    ${PROJECT_SOURCE_DIR}/sema/DeclarationBinder_Specifiers.cpp
    ${PROJECT_SOURCE_DIR}/sema/DeclarationBinder_End.cpp
    ${PROJECT_SOURCE_DIR}/sema/DiagnosticsReporter_DeclarationBinder.cpp
    ${PROJECT_SOURCE_DIR}/sema/DiagnosticsReporter_TypeCanonicalizer.cpp
    ${PROJECT_SOURCE_DIR}/sema/DiagnosticsReporter_TypeChecker.cpp
    ${PROJECT_SOURCE_DIR}/sema/InferenceOptions.h
    ${PROJECT_SOURCE_DIR}/sema/InferenceOptions.cpp
    ${PROJECT_SOURCE_DIR}/sema/LegacyOptions.h
    ${PROJECT_SOURCE_DIR}/sema/LegacyOptions.cpp
    ${PROJECT_SOURCE_DIR}/sema/NameSpace.h
    ${PROJECT_SOURCE_DIR}/sema/PlatformOptions.h
    ${PROJECT_SOURCE_DIR}/sema/PlatformOptions.cpp
    ${PROJECT_SOURCE_DIR}/sema/Scope.h
    ${PROJECT_SOURCE_DIR}/sema/Scope.cpp
    ${PROJECT_SOURCE_DIR}/sema/ScopeKind.h
    ${PROJECT_SOURCE_DIR}/sema/TypeCanonicalizer.h
    ${PROJECT_SOURCE_DIR}/sema/TypeCanonicalizer.cpp
    ${PROJECT_SOURCE_DIR}/sema/TypedefNameTypeResolver.h
    ${PROJECT_SOURCE_DIR}/sema/TypedefNameTypeResolver.cpp
    ${PROJECT_SOURCE_DIR}/sema/TypeChecker.h
    ${PROJECT_SOURCE_DIR}/sema/TypeChecker.cpp
    ${PROJECT_SOURCE_DIR}/sema/TypeInfo.h
    ${PROJECT_SOURCE_DIR}/sema/TypeInfo.cpp
    ${PROJECT_SOURCE_DIR}/sema/Compilation.h
    ${PROJECT_SOURCE_DIR}/sema/Compilation.cpp
    ${PROJECT_SOURCE_DIR}/sema/SemanticModel.h
    ${PROJECT_SOURCE_DIR}/sema/SemanticModel.cpp

    # Types
    ${PROJECT_SOURCE_DIR}/types/Type.h
    ${PROJECT_SOURCE_DIR}/types/Type.cpp
    ${PROJECT_SOURCE_DIR}/types/Type_Array.h
    ${PROJECT_SOURCE_DIR}/types/Type_Array.cpp
    ${PROJECT_SOURCE_DIR}/types/Type_Basic.h
    ${PROJECT_SOURCE_DIR}/types/Type_Basic.cpp
    ${PROJECT_SOURCE_DIR}/types/Type_Error.h
    ${PROJECT_SOURCE_DIR}/types/Type_Error.cpp
    ${PROJECT_SOURCE_DIR}/types/Type_Function.h
    ${PROJECT_SOURCE_DIR}/types/Type_Function.cpp
    ${PROJECT_SOURCE_DIR}/types/Type_Qualified.h
    ${PROJECT_SOURCE_DIR}/types/Type_Qualified.cpp
    ${PROJECT_SOURCE_DIR}/types/Type_Pointer.h
    ${PROJECT_SOURCE_DIR}/types/Type_Pointer.cpp
    ${PROJECT_SOURCE_DIR}/types/Type_TypedefName.h
    ${PROJECT_SOURCE_DIR}/types/Type_TypedefName.cpp
    ${PROJECT_SOURCE_DIR}/types/Type_Tag.h
    ${PROJECT_SOURCE_DIR}/types/Type_Tag.cpp
    ${PROJECT_SOURCE_DIR}/types/Type_Void.h
    ${PROJECT_SOURCE_DIR}/types/Type_Void.cpp
    ${PROJECT_SOURCE_DIR}/types/Type_ALL.h
    ${PROJECT_SOURCE_DIR}/types/Type__IMPL__.inc
    ${PROJECT_SOURCE_DIR}/types/TypeKind.h
    ${PROJECT_SOURCE_DIR}/types/TypeKind_Basic.h
    ${PROJECT_SOURCE_DIR}/types/TypeKind_Tag.h

    # Tests
    ${PROJECT_SOURCE_DIR}/tests/DeclarationBinderTester.h
    ${PROJECT_SOURCE_DIR}/tests/DeclarationBinderTester.cpp
    ${PROJECT_SOURCE_DIR}/tests/DeclarationBinderTester_0000_0999.cpp
    ${PROJECT_SOURCE_DIR}/tests/DeclarationBinderTester_1000_1999.cpp
    ${PROJECT_SOURCE_DIR}/tests/DeclarationBinderTester_2000_2999.cpp
    ${PROJECT_SOURCE_DIR}/tests/DeclarationBinderTester_3000_3999.cpp
    ${PROJECT_SOURCE_DIR}/tests/DeclarationBinderTester_4000_4999.cpp
    ${PROJECT_SOURCE_DIR}/tests/ParserTester.h
    ${PROJECT_SOURCE_DIR}/tests/ParserTester.cpp
    ${PROJECT_SOURCE_DIR}/tests/ParserTester_0000_0999.cpp
    ${PROJECT_SOURCE_DIR}/tests/ParserTester_1000_1999.cpp
    ${PROJECT_SOURCE_DIR}/tests/ParserTester_2000_2999.cpp
    ${PROJECT_SOURCE_DIR}/tests/ParserTester_3000_3999.cpp
    ${PROJECT_SOURCE_DIR}/tests/ReparserTester.h
    ${PROJECT_SOURCE_DIR}/tests/ReparserTester.cpp
    ${PROJECT_SOURCE_DIR}/tests/TypeCanonicalizerAndResolverTester.h
    ${PROJECT_SOURCE_DIR}/tests/TypeCanonicalizerAndResolverTester.cpp
    ${PROJECT_SOURCE_DIR}/tests/TypeCheckerTester.h
    ${PROJECT_SOURCE_DIR}/tests/TypeCheckerTester.cpp
    ${PROJECT_SOURCE_DIR}/tests/SemanticModelTester.h
    ${PROJECT_SOURCE_DIR}/tests/SemanticModelTester.cpp
    ${PROJECT_SOURCE_DIR}/tests/TestExpectation.h
    ${PROJECT_SOURCE_DIR}/tests/TestExpectation.cpp
    ${PROJECT_SOURCE_DIR}/tests/TestSuite_API.h
    ${PROJECT_SOURCE_DIR}/tests/TestSuite_API.cpp
    ${PROJECT_SOURCE_DIR}/tests/TestSuite_Internals.h
    ${PROJECT_SOURCE_DIR}/tests/TestSuite_Internals.cpp
)

foreach(file ${PLUGIN_SOURCES})
    set_source_files_properties(
        ${file} PROPERTIES
        COMPILE_FLAGS "${PLUGIN_CXX_FLAGS}"
    )
endforeach()

foreach(file ${CFE_SOURCES})
    set_source_files_properties(
        ${file} PROPERTIES
        COMPILE_FLAGS "${CFE_CXX_FLAGS}"
    )
endforeach()

include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/..
)

set(LIBRARY psychecfe)
add_library(${LIBRARY} SHARED ${CFE_SOURCES} ${PLUGIN_SOURCES})

target_link_libraries(${LIBRARY} psychecommon)

# Install setup
install(TARGETS ${LIBRARY} DESTINATION ${PROJECT_SOURCE_DIR}/../../../Deliverable)
