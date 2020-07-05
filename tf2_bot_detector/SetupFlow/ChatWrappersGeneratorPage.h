#pragma once

#include "FileMods.h"
#include "ISetupFlowPage.h"

#include <future>

namespace tf2_bot_detector
{
	class ChatWrappersGeneratorPage final : public ISetupFlowPage
	{
	public:
		bool ValidateSettings(const Settings& settings) const override;
		OnDrawResult OnDraw(const DrawState& ds) override;
		void Init(const Settings& settings) override;

		bool CanCommit() const override;
		void Commit(Settings& settings);

		bool WantsSetupText() const override { return false; }
		bool WantsContinueButton() const override { return false; }

		static std::string GetChatWrapperStringToken(uint32_t token);
		static constexpr char VERIFY_CFG_FILE_NAME[] = "__tf2bd_chat_wrappers_verify.cfg";

	private:
		std::future<ChatWrappers> m_ChatWrappers;
	};
}
