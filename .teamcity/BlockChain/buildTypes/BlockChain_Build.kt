package BlockChain.buildTypes

import jetbrains.buildServer.configs.kotlin.v2017_2.*
import jetbrains.buildServer.configs.kotlin.v2017_2.buildSteps.VisualStudioStep
import jetbrains.buildServer.configs.kotlin.v2017_2.buildSteps.ant
import jetbrains.buildServer.configs.kotlin.v2017_2.buildSteps.dotnetBuild
import jetbrains.buildServer.configs.kotlin.v2017_2.buildSteps.dotnetRestore
import jetbrains.buildServer.configs.kotlin.v2017_2.buildSteps.visualStudio
import jetbrains.buildServer.configs.kotlin.v2017_2.triggers.vcs

object BlockChain_Build : BuildType({
    uuid = "e8ea34ee-f569-489d-a784-ad8e4d188841"
    id = "BlockChain_Build"
    name = "Build"

    vcs {
        root(BlockChain.vcsRoots.BlockChain_HttpsGithubComSNovakInCommBlockChainRefsHeadsMaster)

    }

    steps {
        dotnetRestore {
            projects = "Building_Blockchain.sln"
        }
        dotnetBuild {
            projects = "Building_Blockchain.sln"
        }
        visualStudio {
            enabled = false
            path = "Building_Blockchain.sln"
            version = VisualStudioStep.VisualStudioVersion.vs2013
            msBuildVersion = VisualStudioStep.MSBuildVersion.V12_0
            msBuildToolsVersion = VisualStudioStep.MSBuildToolsVersion.V12_0
        }
    }

    triggers {
        vcs {
        }
    }
})
