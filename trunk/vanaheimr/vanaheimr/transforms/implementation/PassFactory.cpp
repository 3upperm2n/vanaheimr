/*! \file   PassFactory.cpp
	\date   Wednesday May 2, 2012
	\author Gregory Diamos <gdiamos@nvidia.com>
	\brief  The source file for the PassFactory class.
	
*/

// Vanaheimr Includes
#include <vanaheimr/transforms/interface/PassFactory.h>

#include <vanaheimr/transforms/interface/ConvertToSSAPass.h>
#include <vanaheimr/transforms/interface/ConvertFromSSAPass.h>

#include <vanaheimr/codegen/interface/EnforceArchaeopteryxABIPass.h>
#include <vanaheimr/codegen/interface/ListInstructionSchedulerPass.h>
#include <vanaheimr/codegen/interface/ChaitinBriggsRegisterAllocatorPass.h>
#include <vanaheimr/codegen/interface/GenericSpillCodePass.h>
#include <vanaheimr/codegen/interface/TranslationTableInstructionSelectionPass.h>

namespace vanaheimr
{

namespace transforms
{

Pass* PassFactory::createPass(const std::string& name,
	const StringVector& options)
{
	Pass* pass = nullptr;

	if(name == "ConvertToSSA" || name == "ConvertToSSAPass")
	{
		pass = new ConvertToSSAPass();
	}
	
	if(name == "ConvertFromSSA" || name == "ConvertFromSSAPass")
	{
		pass = new ConvertFromSSAPass();
	}
	
	if(name == "EnforceArchaeopteryxABIPass")
	{
		pass = new codegen::EnforceArchaeopteryxABIPass();
	}
	
	if(name == "ListInstructionSchedulerPass" || name == "list")
	{
		pass = new codegen::ListInstructionSchedulerPass();
	}
	
	if(name == "chaitin-briggs" || name == "ChaitinBriggsRegisterAllocatorPass")
	{
		pass = new codegen::ChaitinBriggsRegisterAllocatorPass();
	}
	
	if(name == "generic-spiller" || name == "GenericSpillCodePass")
	{
		pass = new codegen::GenericSpillCodePass();
	}
	
	if(name == "translation-table" ||
		name == "TranslationTableInstructionSelectionPass")
	{
		pass = new codegen::TranslationTableInstructionSelectionPass();
	}
	
	if(pass != nullptr)
	{
		pass->configure(options);
	}
	
	return pass;
}

}

}
