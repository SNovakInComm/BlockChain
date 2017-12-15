package BlockChain.vcsRoots

import jetbrains.buildServer.configs.kotlin.v2017_2.*
import jetbrains.buildServer.configs.kotlin.v2017_2.vcs.GitVcsRoot

object BlockChain_HttpsGithubComSNovakInCommBlockChainRefsHeadsMaster : GitVcsRoot({
    uuid = "7c1ef568-e9c5-4cf8-bf60-354ff2b8c563"
    id = "BlockChain_HttpsGithubComSNovakInCommBlockChainRefsHeadsMaster"
    name = "https://github.com/SNovakInComm/BlockChain#refs/heads/master"
    url = "https://github.com/SNovakInComm/BlockChain"
    branchSpec = "+:refs/heads/(*)"
    authMethod = password {
        userName = "SNovakInComm"
        password = "credentialsJSON:3285439e-a9d8-4d27-9a7d-5fd45dfd30f0"
    }
})
