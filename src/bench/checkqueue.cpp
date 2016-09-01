// Copyright (c) 2015 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "bench.h"
#include "util.h"
#include "main.h"
#include "checkqueue.h"
#include "prevector.h"
#include <boost/thread/thread.hpp>

static void CCheckQueueSpeed(benchmark::State& state)
{
    struct FakeJobNoWork {
        bool operator()()
        {
            return true;
        }
        void swap(FakeJobNoWork& x){};
    };
    const unsigned int batch_size = 128;
    CCheckQueue<FakeJobNoWork> queue {batch_size};
    queue.init(std::max(2, GetNumCores()));
    while (state.KeepRunning()) {
        CCheckQueueControl<FakeJobNoWork> control(&queue);
        for (size_t j = 0; j < 101; ++j) {
            size_t r = 30;
            auto emplacer = control.get_emplacer();
            for (size_t k = 0; k < r; ++k)
                emplacer(FakeJobNoWork{});
        }
    }
}

static void CCheckQueueSpeedPrevectorJob(benchmark::State& state)
{
    struct PrevectorJob {
        prevector<28, uint8_t> p;
        PrevectorJob(){
            p.resize(insecure_rand() % 56);
        }
        bool operator()()
        {
            return true;
        }
        void swap(PrevectorJob& x){p.swap(x.p);};
    };
    seed_insecure_rand(true);
    const unsigned int batch_size = 128;
    CCheckQueue<PrevectorJob> queue {batch_size};
    queue.init(std::max(2, GetNumCores()));
    while (state.KeepRunning()) {
        CCheckQueueControl<PrevectorJob> control(&queue);
        for (size_t j = 0; j < 101; ++j) {
            size_t r = 30;
            auto emplacer = control.get_emplacer();
            for (size_t k = 0; k < r; ++k)
                emplacer(PrevectorJob{});
        }
    }
    seed_insecure_rand(false);
}
BENCHMARK(CCheckQueueSpeed);
BENCHMARK(CCheckQueueSpeedPrevectorJob);
