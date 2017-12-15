package BlockChain

import BlockChain.buildTypes.*
import BlockChain.vcsRoots.*
import BlockChain.vcsRoots.BlockChain_HttpsGithubComSNovakInCommBlockChainRefsHeadsMaster
import jetbrains.buildServer.configs.kotlin.v2017_2.*
import jetbrains.buildServer.configs.kotlin.v2017_2.Project
import jetbrains.buildServer.configs.kotlin.v2017_2.projectFeatures.VersionedSettings
import jetbrains.buildServer.configs.kotlin.v2017_2.projectFeatures.versionedSettings

object Project : Project({
    uuid = "0f4774c8-d675-4e9d-b334-103aee99a604"
    id = "BlockChain"
    parentId = "_Root"
    name = "BlockChain"

    vcsRoot(BlockChain_HttpsGithubComSNovakInCommBlockChainRefsHeadsMaster)

    buildType(BlockChain_Build)

    features {
        versionedSettings {
            id = "PROJECT_EXT_7"
            mode = VersionedSettings.Mode.ENABLED
            buildSettingsMode = VersionedSettings.BuildSettingsMode.PREFER_SETTINGS_FROM_VCS
            rootExtId = BlockChain_HttpsGithubComSNovakInCommBlockChainRefsHeadsMaster.id
            showChanges = false
            settingsFormat = VersionedSettings.Format.KOTLIN
            storeSecureParamsOutsideOfVcs = true
        }
    }
})
